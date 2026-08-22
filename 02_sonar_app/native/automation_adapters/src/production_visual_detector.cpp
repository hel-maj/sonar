#include "production_visual_detector.h"

#include "sonar/fishing/automation_adapters/frame_semantics.h"
#include "visual_assets.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_set>
#include <utility>
#include <vector>

namespace sonar::fishing::automation_adapters::detail {
namespace {

struct pixel_rect final {
  std::uint32_t x{};
  std::uint32_t y{};
  std::uint32_t width{};
  std::uint32_t height{};
};

struct rgba_image final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::vector<std::uint8_t> pixels;
  std::uint32_t alpha_left{};
  std::uint32_t alpha_top{};
  std::uint32_t alpha_right{};
  std::uint32_t alpha_bottom{};
};

struct decoded_asset final {
  std::string id;
  visual_asset_kind kind{};
  std::string profile;
  rgba_image image;
};

struct slot_geometry final {
  inventory_store::inventory_compartment compartment{};
  std::uint32_t columns{};
  std::uint32_t rows{};
  double left{};
  double top{};
  double right{};
  double bottom{};
};

constexpr slot_geometry kPlayerInventory{
    inventory_store::inventory_compartment::player_inventory,
    6U, 17U, 0.6100, 0.0850, 0.7800, 0.9430};
constexpr slot_geometry kBackpack{
    inventory_store::inventory_compartment::backpack,
    6U, 8U, 0.2200, 0.5390, 0.3900, 0.9430};

[[nodiscard]] std::vector<std::uint8_t> decode_base64(
    const std::string_view source) {
  constexpr std::string_view alphabet =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::vector<std::uint8_t> result;
  result.reserve(source.size() * 3U / 4U);
  std::uint32_t accumulator{};
  int bits{};
  for (const char character : source) {
    if (character == '=') {
      break;
    }
    const auto position = alphabet.find(character);
    if (position == std::string_view::npos) {
      return {};
    }
    accumulator = (accumulator << 6U) |
        static_cast<std::uint32_t>(position);
    bits += 6;
    if (bits >= 8) {
      bits -= 8;
      result.push_back(static_cast<std::uint8_t>(
          (accumulator >> bits) & 0xFFU));
    }
  }
  return result;
}

[[nodiscard]] const std::vector<decoded_asset>& catalog() {
  static const auto value = [] {
    std::vector<decoded_asset> result;
    result.reserve(embedded_visual_assets().size());
    for (const auto& asset : embedded_visual_assets()) {
      auto pixels = decode_base64(asset.rgba_base64);
      const auto expected = static_cast<std::size_t>(asset.width) *
          asset.height * 4U;
      if (asset.id.empty() || asset.source_sha256.size() != 64U ||
          pixels.size() != expected) {
        return std::vector<decoded_asset>{};
      }
      std::uint32_t alpha_left = asset.width;
      std::uint32_t alpha_top = asset.height;
      std::uint32_t alpha_right{};
      std::uint32_t alpha_bottom{};
      for (std::uint32_t y = 0U; y < asset.height; ++y) {
        for (std::uint32_t x = 0U; x < asset.width; ++x) {
          const auto alpha = pixels[
              (static_cast<std::size_t>(y) * asset.width + x) * 4U + 3U];
          if (alpha < 72U) {
            continue;
          }
          alpha_left = (std::min)(alpha_left, x);
          alpha_top = (std::min)(alpha_top, y);
          alpha_right = (std::max)(alpha_right, x + 1U);
          alpha_bottom = (std::max)(alpha_bottom, y + 1U);
        }
      }
      if (alpha_left >= alpha_right || alpha_top >= alpha_bottom) {
        return std::vector<decoded_asset>{};
      }
      result.push_back({
          .id = std::string(asset.id),
          .kind = asset.kind,
          .profile = std::string(asset.profile),
          .image = {
              asset.width,
              asset.height,
              std::move(pixels),
              alpha_left,
              alpha_top,
              alpha_right,
              alpha_bottom,
          },
      });
    }
    return result;
  }();
  return value;
}

[[nodiscard]] pixel_rect normalized_rect(
    const runtime_platform::client_frame& frame,
    const double left,
    const double top,
    const double right,
    const double bottom) noexcept {
  const auto x0 = static_cast<std::uint32_t>(std::clamp(
      std::llround(left * frame.width), 0LL,
      static_cast<long long>(frame.width - 1U)));
  const auto y0 = static_cast<std::uint32_t>(std::clamp(
      std::llround(top * frame.height), 0LL,
      static_cast<long long>(frame.height - 1U)));
  const auto x1 = static_cast<std::uint32_t>(std::clamp(
      std::llround(right * frame.width),
      static_cast<long long>(x0 + 1U),
      static_cast<long long>(frame.width)));
  const auto y1 = static_cast<std::uint32_t>(std::clamp(
      std::llround(bottom * frame.height),
      static_cast<long long>(y0 + 1U),
      static_cast<long long>(frame.height)));
  return {x0, y0, x1 - x0, y1 - y0};
}

[[nodiscard]] stage_detection::normalized_rect as_normalized(
    const pixel_rect& value,
    const runtime_platform::client_frame& frame) noexcept {
  return {
      static_cast<double>(value.x) / frame.width,
      static_cast<double>(value.y) / frame.height,
      static_cast<double>(value.width) / frame.width,
      static_cast<double>(value.height) / frame.height,
  };
}

[[nodiscard]] stage_detection::normalized_rect inset(
    const stage_detection::normalized_rect& value,
    const double ratio = 0.10) noexcept {
  return {
      value.x + value.width * ratio,
      value.y + value.height * ratio,
      value.width * (1.0 - ratio * 2.0),
      value.height * (1.0 - ratio * 2.0),
  };
}

[[nodiscard]] pixel_rect slot_rect(
    const runtime_platform::client_frame& frame,
    const slot_geometry& geometry,
    const std::uint32_t column,
    const std::uint32_t row) noexcept {
  const double cell_width = (geometry.right - geometry.left) /
      geometry.columns;
  const double cell_height = (geometry.bottom - geometry.top) /
      geometry.rows;
  return normalized_rect(
      frame,
      geometry.left + cell_width * column,
      geometry.top + cell_height * row,
      geometry.left + cell_width * (column + 1U),
      geometry.top + cell_height * (row + 1U));
}

[[nodiscard]] bool occupied_slot(
    const runtime_platform::client_frame& frame,
    const pixel_rect& slot) noexcept {
  double sum{};
  double squared{};
  std::size_t colorful{};
  std::size_t count{};
  // Exclude the grid border itself while retaining narrow tackle/food shapes.
  // This is only a performance prefilter: exact template correlation remains
  // the authority for classification.
  const auto left = slot.x + slot.width / 8U;
  const auto right = slot.x + slot.width - slot.width / 8U;
  const auto top = slot.y + slot.height / 8U;
  const auto bottom = slot.y + slot.height - slot.height / 8U;
  for (std::uint32_t y = top; y < bottom; y += 2U) {
    for (std::uint32_t x = left; x < right; x += 2U) {
      const auto offset = static_cast<std::size_t>(y) * frame.stride_bytes +
          static_cast<std::size_t>(x) * 3U;
      const auto blue = frame.bgr24[offset];
      const auto green = frame.bgr24[offset + 1U];
      const auto red = frame.bgr24[offset + 2U];
      const double gray = 0.114 * blue + 0.587 * green + 0.299 * red;
      sum += gray;
      squared += gray * gray;
      const auto maximum = (std::max)({blue, green, red});
      const auto minimum = (std::min)({blue, green, red});
      colorful += maximum > 55U && maximum - minimum > 28U ? 1U : 0U;
      ++count;
    }
  }
  if (count == 0U) {
    return false;
  }
  const double mean = sum / count;
  const double variance = (std::max)(0.0, squared / count - mean * mean);
  return std::sqrt(variance) >= 10.0 ||
      static_cast<double>(colorful) / count >= 0.012;
}

[[nodiscard]] double normalized_correlation(
    const double count,
    const double sum_left,
    const double sum_right,
    const double squares_left,
    const double squares_right,
    const double products) noexcept {
  if (count < 24.0) {
    return 0.0;
  }
  const double covariance = products - sum_left * sum_right / count;
  const double variance_left = squares_left - sum_left * sum_left / count;
  const double variance_right = squares_right - sum_right * sum_right / count;
  if (variance_left <= 1.0 || variance_right <= 1.0) {
    return 0.0;
  }
  return std::clamp(
      covariance / std::sqrt(variance_left * variance_right), -1.0, 1.0);
}

// Mirrors the retired cv2.TM_CCOEFF_NORMED contract over the complete source
// image (including its transparent-background RGB). Inventory assets were
// captured at their actual FHD/2K UI size, so preserving that complete shape is
// substantially more selective than correlating only the opaque foreground.
[[nodiscard]] double compare_complete_asset_at(
    const runtime_platform::client_frame& frame,
    const rgba_image& asset,
    const double center_x,
    const double center_y,
    const double scale,
    const int offset_x,
    const int offset_y) noexcept {
  if (asset.pixels.size() != static_cast<std::size_t>(asset.width) *
          asset.height * 4U || !std::isfinite(scale) || scale <= 0.0) {
    return 0.0;
  }
  const auto target_width = (std::max)(
      2LL, std::llround(static_cast<double>(asset.width) * scale));
  const auto target_height = (std::max)(
      2LL, std::llround(static_cast<double>(asset.height) * scale));
  const auto left = std::llround(center_x - target_width / 2.0) + offset_x;
  const auto top = std::llround(center_y - target_height / 2.0) + offset_y;
  if (left < 0LL || top < 0LL ||
      left + target_width > static_cast<long long>(frame.width) ||
      top + target_height > static_cast<long long>(frame.height)) {
    return 0.0;
  }

  double count{};
  double source_sum{};
  double target_sum{};
  double source_squared{};
  double target_squared{};
  double products{};
  for (long long y = 0LL; y < target_height; y += 2LL) {
    const auto source_y = static_cast<std::uint32_t>(std::clamp(
        std::llround((static_cast<double>(y) + 0.5) / target_height *
                     asset.height - 0.5),
        0LL, static_cast<long long>(asset.height - 1U)));
    for (long long x = 0LL; x < target_width; x += 2LL) {
      const auto source_x = static_cast<std::uint32_t>(std::clamp(
          std::llround((static_cast<double>(x) + 0.5) / target_width *
                       asset.width - 0.5),
          0LL, static_cast<long long>(asset.width - 1U)));
      const auto source =
          (static_cast<std::size_t>(source_y) * asset.width + source_x) * 4U;
      const auto target = static_cast<std::size_t>(top + y) *
              frame.stride_bytes +
          static_cast<std::size_t>(left + x) * 3U;
      const double source_luma =
          0.299 * asset.pixels[source] +
          0.587 * asset.pixels[source + 1U] +
          0.114 * asset.pixels[source + 2U];
      const double target_luma =
          0.299 * frame.bgr24[target + 2U] +
          0.587 * frame.bgr24[target + 1U] +
          0.114 * frame.bgr24[target];
      source_sum += source_luma;
      target_sum += target_luma;
      source_squared += source_luma * source_luma;
      target_squared += target_luma * target_luma;
      products += source_luma * target_luma;
      ++count;
    }
  }
  return normalized_correlation(
      count, source_sum, target_sum, source_squared, target_squared, products);
}

[[nodiscard]] double compare_complete_asset_to_slot(
    const runtime_platform::client_frame& frame,
    const pixel_rect& slot,
    const rgba_image& asset,
    const bool asset_is_two_k) noexcept {
  const double reference_width = asset_is_two_k ? 2560.0 : 1920.0;
  const double reference_height = asset_is_two_k ? 1440.0 : 1080.0;
  const double scale = (static_cast<double>(frame.width) / reference_width +
                        static_cast<double>(frame.height) / reference_height) /
      2.0;
  constexpr std::array offsets{-12, -8, -4, 0, 4, 8, 12};
  double best{};
  for (const int offset_y : offsets) {
    for (const int offset_x : offsets) {
      best = (std::max)(best, compare_complete_asset_at(
          frame, asset,
          slot.x + slot.width / 2.0,
          slot.y + slot.height / 2.0,
          scale, offset_x, offset_y));
    }
  }
  return best;
}

[[nodiscard]] double compare_asset_to_slot(
    const runtime_platform::client_frame& frame,
    const pixel_rect& slot,
    const rgba_image& asset) noexcept {
  if (asset.pixels.size() != static_cast<std::size_t>(asset.width) *
          asset.height * 4U || slot.width < 4U || slot.height < 4U) {
    return 0.0;
  }
  const auto content_width = asset.alpha_right - asset.alpha_left;
  const auto content_height = asset.alpha_bottom - asset.alpha_top;
  const double aspect = static_cast<double>(content_width) / content_height;
  double best{};
  constexpr std::array ratios{0.64, 0.76, 0.88};
  constexpr std::array offsets{-2, 0, 2};
  for (const auto ratio : ratios) {
    double target_width = slot.width * ratio;
    double target_height = target_width / aspect;
    if (target_height > slot.height * ratio) {
      target_height = slot.height * ratio;
      target_width = target_height * aspect;
    }
    for (const int offset_y : offsets) {
      for (const int offset_x : offsets) {
        double count{};
        double template_luma{};
        double screen_luma{};
        double template_luma_squared{};
        double screen_luma_squared{};
        double luma_products{};
        double template_chroma{};
        double screen_chroma{};
        double template_chroma_squared{};
        double screen_chroma_squared{};
        double chroma_products{};
        double absolute_error{};
        for (std::uint32_t sy = asset.alpha_top;
             sy < asset.alpha_bottom; sy += 2U) {
          for (std::uint32_t sx = asset.alpha_left;
               sx < asset.alpha_right; sx += 2U) {
            const auto source =
                (static_cast<std::size_t>(sy) * asset.width + sx) * 4U;
            if (asset.pixels[source + 3U] < 96U) {
              continue;
            }
            const double normalized_x =
                (static_cast<double>(sx - asset.alpha_left) + 0.5) /
                content_width - 0.5;
            const double normalized_y =
                (static_cast<double>(sy - asset.alpha_top) + 0.5) /
                content_height - 0.5;
            const auto x = static_cast<long long>(std::llround(
                slot.x + slot.width / 2.0 + normalized_x * target_width +
                offset_x));
            const auto y = static_cast<long long>(std::llround(
                slot.y + slot.height / 2.0 + normalized_y * target_height +
                offset_y));
            if (x < static_cast<long long>(slot.x) ||
                y < static_cast<long long>(slot.y) ||
                x >= static_cast<long long>(slot.x + slot.width) ||
                y >= static_cast<long long>(slot.y + slot.height)) {
              continue;
            }
            const auto target = static_cast<std::size_t>(y) *
                    frame.stride_bytes +
                static_cast<std::size_t>(x) * 3U;
            const double source_luma =
                0.299 * asset.pixels[source] +
                0.587 * asset.pixels[source + 1U] +
                0.114 * asset.pixels[source + 2U];
            const double target_luma =
                0.299 * frame.bgr24[target + 2U] +
                0.587 * frame.bgr24[target + 1U] +
                0.114 * frame.bgr24[target];
            const double source_chroma =
                static_cast<int>(asset.pixels[source]) -
                static_cast<int>(asset.pixels[source + 2U]);
            const double target_chroma =
                static_cast<int>(frame.bgr24[target + 2U]) -
                static_cast<int>(frame.bgr24[target]);
            template_luma += source_luma;
            screen_luma += target_luma;
            template_luma_squared += source_luma * source_luma;
            screen_luma_squared += target_luma * target_luma;
            luma_products += source_luma * target_luma;
            template_chroma += source_chroma;
            screen_chroma += target_chroma;
            template_chroma_squared += source_chroma * source_chroma;
            screen_chroma_squared += target_chroma * target_chroma;
            chroma_products += source_chroma * target_chroma;
            absolute_error += std::abs(source_luma - target_luma);
            ++count;
          }
        }
        if (count < 24.0) {
          continue;
        }
        const double luma = (std::max)(0.0, normalized_correlation(
            count, template_luma, screen_luma,
            template_luma_squared, screen_luma_squared, luma_products));
        const double chroma = (std::max)(0.0, normalized_correlation(
            count, template_chroma, screen_chroma,
            template_chroma_squared, screen_chroma_squared,
            chroma_products));
        const double color = 1.0 -
            (std::min)(1.0, absolute_error / count / 160.0);
        best = (std::max)(best, luma * 0.60 + chroma * 0.25 + color * 0.15);
      }
    }
  }
  return best;
}

struct classified_item final {
  std::string id;
  visual_asset_kind kind{};
  double confidence{};
};

[[nodiscard]] std::optional<classified_item> classify(
    const runtime_platform::client_frame& frame,
    const pixel_rect& slot,
    const bool two_k) {
  std::optional<classified_item> best;
  for (const auto& candidate : catalog()) {
    if (candidate.kind != visual_asset_kind::fish &&
        candidate.kind != visual_asset_kind::food &&
        candidate.kind != visual_asset_kind::garbage) {
      continue;
    }
    if (candidate.profile != "any" &&
        candidate.profile != (two_k ? "2k" : "fhd")) {
      continue;
    }
    const auto confidence = compare_complete_asset_to_slot(
        frame, slot, candidate.image, candidate.profile == "2k");
    if (!best.has_value() || confidence > best->confidence) {
      best = classified_item{candidate.id, candidate.kind, confidence};
    }
  }
  // Exact thresholds are the frozen legacy matcher thresholds. Domain state
  // machines require >= 0.90 for destructive fish/context operations; food
  // and garbage operations retain their independently characterized limits.
  if (!best.has_value()) {
    return std::nullopt;
  }
  const double threshold = best->kind == visual_asset_kind::fish
      ? 0.90
      : best->kind == visual_asset_kind::garbage ? 0.80 : 0.75;
  if (best->confidence < threshold) {
    return std::nullopt;
  }
  if (best->kind != visual_asset_kind::fish) {
    const double range = best->kind == visual_asset_kind::garbage
        ? 0.20
        : 0.25;
    best->confidence = (std::min)(
        0.99, 0.90 + (best->confidence - threshold) / range * 0.09);
  }
  return best;
}

[[nodiscard]] bool dark_inventory_panel(
    const runtime_platform::client_frame& frame) noexcept {
  const auto panel = normalized_rect(frame, 0.205, 0.03, 0.795, 0.97);
  std::size_t dark{};
  std::size_t sampled{};
  for (std::uint32_t y = panel.y; y < panel.y + panel.height; y += 8U) {
    for (std::uint32_t x = panel.x; x < panel.x + panel.width; x += 8U) {
      const auto offset = static_cast<std::size_t>(y) * frame.stride_bytes +
          static_cast<std::size_t>(x) * 3U;
      dark += frame.bgr24[offset] < 75U &&
          frame.bgr24[offset + 1U] < 75U &&
          frame.bgr24[offset + 2U] < 75U ? 1U : 0U;
      ++sampled;
    }
  }
  return sampled != 0U && static_cast<double>(dark) / sampled >= 0.52;
}

[[nodiscard]] maintenance_episode::tackle_scan_observation detect_tackle(
    const runtime_platform::client_frame& frame) noexcept {
  maintenance_episode::tackle_scan_observation result{
      .available = true,
      .readable = true,
  };
  constexpr std::array<double, 6> centers{
      0.375, 0.417, 0.459, 0.501, 0.543, 0.585};
  std::array<std::uint32_t*, 6> counts{
      &result.counts.rod, &result.counts.reel, &result.counts.line,
      &result.counts.hook, &result.counts.bait, &result.counts.net};
  for (std::size_t index = 0U; index < centers.size(); ++index) {
    const auto slot = normalized_rect(
        frame, centers[index] - 0.019, 0.862,
        centers[index] + 0.019, 0.930);
    *counts[index] = occupied_slot(frame, slot) ? 1 : 0;
  }
  return result;
}

[[nodiscard]] bool has_cue(
    const runtime_platform::client_frame& frame,
    const std::string_view cue,
    const bool two_k) noexcept {
  // Legacy need indicators occupy the left/bottom HUD. A masked descriptor
  // comparison is deliberately limited to its normalized union. This remains
  // a conservative fallback behind coherent memory evidence.
  const auto roi = normalized_rect(frame, 0.0, 0.55, 0.36, 0.99);
  for (const auto& candidate : catalog()) {
    if (candidate.kind != visual_asset_kind::hud_cue ||
        candidate.id != cue ||
        candidate.profile != (two_k ? "2k" : "fhd")) {
      continue;
    }
    const auto width = (std::max)(candidate.image.width, 1U);
    const auto height = (std::max)(candidate.image.height, 1U);
    const std::uint32_t step_x = (std::max)(2U, width / 3U);
    const std::uint32_t step_y = (std::max)(2U, height / 3U);
    for (std::uint32_t y = roi.y;
         y + height <= roi.y + roi.height; y += step_y) {
      for (std::uint32_t x = roi.x;
           x + width <= roi.x + roi.width; x += step_x) {
        if (compare_asset_to_slot(
                frame, {x, y, width, height}, candidate.image) >= 0.82) {
          return true;
        }
      }
    }
  }
  return false;
}

[[nodiscard]] std::optional<
    inventory_store::inventory_context_action_observation>
detect_remove_action(
    const runtime_platform::client_frame& frame,
    const std::string_view expected_instance,
    const stage_detection::normalized_rect& expected_bounds,
    const bool two_k) noexcept {
  const auto search = normalized_rect(
      frame,
      (std::max)(0.0, expected_bounds.x - 0.12),
      (std::max)(0.0, expected_bounds.y - 0.10),
      (std::min)(1.0,
          expected_bounds.x + expected_bounds.width + 0.20),
      (std::min)(1.0,
          expected_bounds.y + expected_bounds.height + 0.20));
  double best{};
  pixel_rect best_bounds{};
  for (const auto& candidate : catalog()) {
    if (candidate.kind != visual_asset_kind::context_action ||
        candidate.profile != (two_k ? "2k" : "fhd")) {
      continue;
    }
    const double reference_width = two_k ? 2560.0 : 1920.0;
    const double reference_height = two_k ? 1440.0 : 1080.0;
    const double scale =
        (static_cast<double>(frame.width) / reference_width +
         static_cast<double>(frame.height) / reference_height) /
        2.0;
    const auto width = static_cast<std::uint32_t>((std::max)(
        2LL, std::llround(candidate.image.width * scale)));
    const auto height = static_cast<std::uint32_t>((std::max)(
        2LL, std::llround(candidate.image.height * scale)));
    if (width > search.width || height > search.height) {
      continue;
    }
    const auto step_x = (std::max)(2U, width / 24U);
    const auto step_y = (std::max)(2U, height / 3U);
    for (std::uint32_t top = search.y;
         top + height <= search.y + search.height;
         top += step_y) {
      for (std::uint32_t left = search.x;
           left + width <= search.x + search.width;
           left += step_x) {
        const auto score = compare_complete_asset_at(
            frame, candidate.image,
            left + width / 2.0, top + height / 2.0,
            scale, 0, 0);
        if (score > best) {
          best = score;
          best_bounds = {left, top, width, height};
        }
      }
    }
  }
  if (best < 0.90) {
    return std::nullopt;
  }
  return inventory_store::inventory_context_action_observation{
      .item_instance_id = std::string(expected_instance),
      .confidence = best,
      .bounds = as_normalized(best_bounds, frame),
  };
}

}  // namespace

visual_catch_surface production_visual_detector::detect_catch(
    const runtime_platform::client_frame& frame) const noexcept {
  if (!frame.valid() || !detect_frame_semantics(frame).catch_visible) {
    return {};
  }
  // Exact legacy panel-relative regions projected into normalized client
  // coordinates. They scale with the actual panel, never a screen resolution.
  constexpr stage_detection::normalized_rect panel{
      0.385, 0.265, 0.230, 0.465};
  const auto relative = [](const double x, const double y,
                           const double width, const double height) {
    return stage_detection::normalized_rect{
        panel.x + panel.width * x,
        panel.y + panel.height * y,
        panel.width * width,
        panel.height * height,
    };
  };
  return {
      .visible = true,
      .inventory_full = has_cue(
          frame, "overweight",
          frame.width >= 2500U || frame.height >= 1300U),
      .keep_button = relative(0.08, 0.80, 0.42, 0.11),
      .release_button = relative(0.52, 0.80, 0.42, 0.11),
      .fish_text = relative(0.10, 0.56, 0.45, 0.08),
      .quality_text = relative(0.10, 0.18, 0.42, 0.08),
      .weight_text = relative(0.68, 0.52, 0.28, 0.12),
      .experience_text = relative(0.06, 0.68, 0.88, 0.10),
  };
}

visual_inventory_surface production_visual_detector::detect_inventory(
    const runtime_platform::client_frame& frame,
    const bool inventory_title_confirmed,
    const std::optional<std::string_view> expected_context_instance,
    const std::optional<stage_detection::normalized_rect>
        expected_context_bounds)
    const noexcept {
  visual_inventory_surface result;
  if (!frame.valid()) {
    return result;
  }
  const bool two_k = frame.width >= 2500U || frame.height >= 1300U;
  const bool inventory_visible = inventory_title_confirmed &&
      dark_inventory_panel(frame);
  if (!inventory_visible) {
    result.surface = inventory_store::inventory_surface::gameplay;
    result.tackle = detect_tackle(frame);
    result.hunger_visible = has_cue(frame, "hunger", two_k);
    result.thirst_visible = has_cue(frame, "thirst", two_k);
    result.changed_bait_visible = has_cue(frame, "change_bait", two_k);
    result.gear_visible = has_cue(frame, "gear", two_k);
    return result;
  }

  result.surface = inventory_store::inventory_surface::inventory;
  std::unordered_set<std::string> observed_ids;
  for (const auto& geometry : {kPlayerInventory, kBackpack}) {
    for (std::uint32_t row = 0U; row < geometry.rows; ++row) {
      for (std::uint32_t column = 0U; column < geometry.columns; ++column) {
        const auto slot = slot_rect(frame, geometry, column, row);
        if (!occupied_slot(frame, slot)) {
          continue;
        }
        const auto classified = classify(frame, slot, two_k);
        if (!classified.has_value()) {
          continue;
        }
        const std::string instance =
            (geometry.compartment ==
                    inventory_store::inventory_compartment::player_inventory
                ? "inventory:"
                : "backpack:") +
            std::to_string(row) + ':' + std::to_string(column);
        if (!observed_ids.insert(instance).second) {
          continue;
        }
        result.items.push_back({
            .instance_id = instance,
            .item_id = classified->id,
            .title = {},
            .compartment = geometry.compartment,
            .confidence = classified->confidence,
            .bounds = inset(as_normalized(slot, frame)),
        });
      }
    }
  }
  if (expected_context_instance.has_value() &&
      expected_context_bounds.has_value()) {
    result.remove_action = detect_remove_action(
        frame, *expected_context_instance, *expected_context_bounds, two_k);
    if (result.remove_action.has_value()) {
      result.surface = inventory_store::inventory_surface::item_context_menu;
    }
  }
  return result;
}

}  // namespace sonar::fishing::automation_adapters::detail
