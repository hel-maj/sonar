#pragma once

#include <cstdint>
#include <map>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace sonar::fishing::session_statistics {

struct FishPrice {
  double per_item_min;
  double per_item_max;
  double per_1000_min;
  double per_1000_max;
};

using PriceCatalog = std::map<std::string, FishPrice, std::less<>>;
using CustomPriceCatalog = std::map<std::string, double, std::less<>>;

// Generated from the product-owned, language-neutral fish catalog at configure
// time. The returned value is independent so an Engine session can own it.
[[nodiscard]] PriceCatalog DefaultPriceCatalog();

struct CatchRecord {
  std::optional<std::string_view> fish_id;
  std::optional<std::string_view> fish_name;
  std::optional<double> weight_kg;
  bool kept;
  std::optional<bool> released;
  std::string_view catch_size_key;
};

struct TackleItem {
  std::string key;
  std::string name;
  std::uint32_t count;

  [[nodiscard]] bool operator==(const TackleItem&) const = default;
};

struct FishStatisticsRow {
  std::string fish_id;
  std::string name;
  std::uint64_t caught_count;
  double caught_kg;
  std::uint64_t released_count;
  double released_kg;
  std::uint64_t kept_count;
  double kept_kg;
  std::optional<FishPrice> base_price;
  std::optional<double> custom_price;
  double earned_min;
  double earned_max;
};

struct CatchSizeStatistics {
  std::string key;
  std::string label;
  std::uint64_t count;
  double percent;
};

struct SessionTotals {
  double duration_seconds;
  std::uint64_t caught_count;
  double caught_kg;
  std::uint64_t released_count;
  double released_kg;
  double earned_min;
  double earned_max;

  [[nodiscard]] std::uint64_t kept_count() const noexcept;
  [[nodiscard]] double kept_kg() const noexcept;
};

struct SessionStatisticsSnapshot {
  SessionTotals totals;
  std::vector<FishStatisticsRow> fish_rows;
  std::vector<CatchSizeStatistics> catch_sizes;
  std::vector<TackleItem> tackle_items;
};

// The Engine state-machine thread owns this object. It deliberately contains no
// transport, file persistence, UI, capture, or input behavior. Callers publish
// immutable Snapshot() values across those boundaries.
class SessionStatistics final {
 public:
  explicit SessionStatistics(
      PriceCatalog default_prices = {},
      CustomPriceCatalog custom_prices = {});

  void Reset(double now_seconds);
  void StartTimer(double now_seconds) noexcept;
  void StopTimer(double now_seconds) noexcept;
  void SetCustomPrices(CustomPriceCatalog prices);
  void SetCustomPrice(
      std::string_view fish_id,
      std::optional<double> price);
  void RecordCatch(const CatchRecord& record);
  void SetTackleScan(std::span<const TackleItem> items);
  void ClearTackleScan() noexcept;

  [[nodiscard]] SessionStatisticsSnapshot Snapshot(
      double now_seconds) const;
  [[nodiscard]] bool HasCatches() const noexcept;

 private:
  struct FishStatistics {
    std::string fish_id;
    std::string name;
    std::uint64_t caught_count = 0;
    double caught_kg = 0.0;
    std::uint64_t released_count = 0;
    double released_kg = 0.0;
  };

  [[nodiscard]] SessionTotals Totals(double now_seconds) const;
  [[nodiscard]] double Duration(double now_seconds) const noexcept;
  [[nodiscard]] std::pair<double, double> EffectivePriceRange(
      std::string_view fish_id) const noexcept;

  PriceCatalog default_prices_;
  CustomPriceCatalog custom_prices_;
  std::map<std::string, FishStatistics, std::less<>> fish_;
  std::map<std::string, std::uint64_t, std::less<>> catch_sizes_;
  std::vector<TackleItem> tackle_items_;
  double elapsed_seconds_ = 0.0;
  std::optional<double> running_started_at_;
};

}  // namespace sonar::fishing::session_statistics
