#include "sonar/fishing/session_statistics/session_statistics.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <utility>

namespace sonar::fishing::session_statistics {
namespace {

struct CatchSizeDefinition {
  std::string_view key;
  std::string_view label;
};

constexpr std::array<CatchSizeDefinition, 4> kCatchSizes{{
    {"modest", "Скромный улов"},
    {"good", "Хороший улов"},
    {"record", "Рекордный улов"},
    {"trophy", "Трофейная"},
}};
constexpr std::string_view kUnknownCatchSizeKey = "unknown";
constexpr std::string_view kUnknownCatchSizeLabel = "Не распознано";

[[nodiscard]] bool IsKnownCatchSize(const std::string_view key) noexcept {
  return std::ranges::any_of(
      kCatchSizes,
      [key](const CatchSizeDefinition definition) {
        return definition.key == key;
      });
}

[[nodiscard]] CustomPriceCatalog CleanCustomPrices(
    CustomPriceCatalog prices) {
  std::erase_if(
      prices,
      [](const auto& item) {
        return !(item.second > 0.0);
      });
  return prices;
}

[[nodiscard]] std::string CopyOrFallback(
    const std::optional<std::string_view> value,
    const std::string_view fallback) {
  if (!value.has_value() || value->empty()) {
    return std::string(fallback);
  }
  return std::string(*value);
}

}  // namespace

std::uint64_t SessionTotals::kept_count() const noexcept {
  return caught_count > released_count ? caught_count - released_count : 0;
}

double SessionTotals::kept_kg() const noexcept {
  return std::max(0.0, caught_kg - released_kg);
}

SessionStatistics::SessionStatistics(
    PriceCatalog default_prices,
    CustomPriceCatalog custom_prices)
    : default_prices_(std::move(default_prices)),
      custom_prices_(CleanCustomPrices(std::move(custom_prices))) {
  for (const CatchSizeDefinition definition : kCatchSizes) {
    catch_sizes_.emplace(definition.key, 0);
  }
  catch_sizes_.emplace(kUnknownCatchSizeKey, 0);
}

void SessionStatistics::Reset(const double now_seconds) {
  elapsed_seconds_ = 0.0;
  if (running_started_at_.has_value()) {
    running_started_at_ = now_seconds;
  }
  fish_.clear();
  for (auto& [key, count] : catch_sizes_) {
    (void)key;
    count = 0;
  }
  ClearTackleScan();
}

void SessionStatistics::StartTimer(const double now_seconds) noexcept {
  if (!running_started_at_.has_value()) {
    running_started_at_ = now_seconds;
  }
}

void SessionStatistics::StopTimer(const double now_seconds) noexcept {
  if (!running_started_at_.has_value()) {
    return;
  }
  elapsed_seconds_ += now_seconds - *running_started_at_;
  running_started_at_.reset();
}

void SessionStatistics::SetCustomPrices(CustomPriceCatalog prices) {
  custom_prices_ = CleanCustomPrices(std::move(prices));
}

void SessionStatistics::SetCustomPrice(
    const std::string_view fish_id,
    const std::optional<double> price) {
  if (!price.has_value() || !(*price > 0.0)) {
    const auto existing = custom_prices_.find(fish_id);
    if (existing != custom_prices_.end()) {
      custom_prices_.erase(existing);
    }
    return;
  }
  custom_prices_.insert_or_assign(std::string(fish_id), *price);
}

void SessionStatistics::RecordCatch(const CatchRecord& record) {
  const std::string fish_id = CopyOrFallback(record.fish_id, "unknown");
  const std::string fish_name = CopyOrFallback(record.fish_name, "unknown");
  const double weight = std::max(0.0, record.weight_kg.value_or(0.0));
  const bool released = record.released.value_or(!record.kept);

  auto [iterator, inserted] = fish_.try_emplace(
      fish_id,
      FishStatistics{.fish_id = fish_id, .name = fish_name});
  (void)inserted;
  FishStatistics& statistics = iterator->second;
  statistics.name = fish_name;
  ++statistics.caught_count;
  statistics.caught_kg += weight;
  if (released) {
    ++statistics.released_count;
    statistics.released_kg += weight;
  }

  const std::string_view size_key = IsKnownCatchSize(record.catch_size_key)
      ? record.catch_size_key
      : kUnknownCatchSizeKey;
  ++catch_sizes_[std::string(size_key)];
}

void SessionStatistics::SetTackleScan(
    const std::span<const TackleItem> items) {
  tackle_items_.assign(items.begin(), items.end());
}

void SessionStatistics::ClearTackleScan() noexcept {
  tackle_items_.clear();
}

SessionStatisticsSnapshot SessionStatistics::Snapshot(
    const double now_seconds) const {
  SessionStatisticsSnapshot snapshot{.totals = Totals(now_seconds)};
  snapshot.fish_rows.reserve(fish_.size());
  for (const auto& [fish_id, statistics] : fish_) {
    const auto [price_min, price_max] = EffectivePriceRange(fish_id);
    const double kept_kg = std::max(
        0.0, statistics.caught_kg - statistics.released_kg);
    const std::uint64_t kept_count =
        statistics.caught_count > statistics.released_count
        ? statistics.caught_count - statistics.released_count
        : 0;
    const auto base_price = default_prices_.find(fish_id);
    const auto custom_price = custom_prices_.find(fish_id);
    snapshot.fish_rows.push_back(FishStatisticsRow{
        .fish_id = fish_id,
        .name = statistics.name,
        .caught_count = statistics.caught_count,
        .caught_kg = statistics.caught_kg,
        .released_count = statistics.released_count,
        .released_kg = statistics.released_kg,
        .kept_count = kept_count,
        .kept_kg = kept_kg,
        .base_price = base_price == default_prices_.end()
            ? std::nullopt
            : std::optional<FishPrice>(base_price->second),
        .custom_price = custom_price == custom_prices_.end()
            ? std::nullopt
            : std::optional<double>(custom_price->second),
        .earned_min = kept_kg * price_min,
        .earned_max = kept_kg * price_max,
    });
  }
  std::ranges::sort(
      snapshot.fish_rows,
      {},
      &FishStatisticsRow::name);

  std::uint64_t catch_size_total = 0;
  for (const auto& [key, count] : catch_sizes_) {
    (void)key;
    catch_size_total += count;
  }
  snapshot.catch_sizes.reserve(kCatchSizes.size() + 1);
  for (const CatchSizeDefinition definition : kCatchSizes) {
    const std::uint64_t count = catch_sizes_.find(definition.key)->second;
    snapshot.catch_sizes.push_back(CatchSizeStatistics{
        .key = std::string(definition.key),
        .label = std::string(definition.label),
        .count = count,
        .percent = catch_size_total == 0
            ? 0.0
            : static_cast<double>(count) * 100.0 /
                static_cast<double>(catch_size_total),
    });
  }
  const std::uint64_t unknown_count =
      catch_sizes_.find(kUnknownCatchSizeKey)->second;
  if (unknown_count != 0) {
    snapshot.catch_sizes.push_back(CatchSizeStatistics{
        .key = std::string(kUnknownCatchSizeKey),
        .label = std::string(kUnknownCatchSizeLabel),
        .count = unknown_count,
        .percent = static_cast<double>(unknown_count) * 100.0 /
            static_cast<double>(catch_size_total),
    });
  }
  snapshot.tackle_items = tackle_items_;
  return snapshot;
}

bool SessionStatistics::HasCatches() const noexcept {
  return std::ranges::any_of(
      fish_,
      [](const auto& item) {
        return item.second.caught_count != 0;
      });
}

SessionTotals SessionStatistics::Totals(const double now_seconds) const {
  SessionTotals totals{
      .duration_seconds = Duration(now_seconds),
      .caught_count = 0,
      .caught_kg = 0.0,
      .released_count = 0,
      .released_kg = 0.0,
      .earned_min = 0.0,
      .earned_max = 0.0,
  };
  for (const auto& [fish_id, statistics] : fish_) {
    totals.caught_count += statistics.caught_count;
    totals.caught_kg += statistics.caught_kg;
    totals.released_count += statistics.released_count;
    totals.released_kg += statistics.released_kg;
    const double kept_kg = std::max(
        0.0, statistics.caught_kg - statistics.released_kg);
    const auto [price_min, price_max] = EffectivePriceRange(fish_id);
    totals.earned_min += kept_kg * price_min;
    totals.earned_max += kept_kg * price_max;
  }
  return totals;
}

double SessionStatistics::Duration(const double now_seconds) const noexcept {
  if (!running_started_at_.has_value()) {
    return elapsed_seconds_;
  }
  return elapsed_seconds_ + now_seconds - *running_started_at_;
}

std::pair<double, double> SessionStatistics::EffectivePriceRange(
    const std::string_view fish_id) const noexcept {
  const auto custom = custom_prices_.find(fish_id);
  if (custom != custom_prices_.end()) {
    return {custom->second, custom->second};
  }
  const auto base = default_prices_.find(fish_id);
  if (base == default_prices_.end()) {
    return {0.0, 0.0};
  }
  return {base->second.per_1000_min, base->second.per_1000_max};
}

}  // namespace sonar::fishing::session_statistics
