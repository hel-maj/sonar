#include "sonar/fishing/game_chat/chat_observation.h"

#include "chat_image_ops.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <optional>
#include <ranges>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::game_chat {
namespace {

using detail::binary_component;
using detail::byte_image;

[[nodiscard]] std::uint32_t scaled_floor(
    const std::uint32_t value,
    const double factor) noexcept {
  return static_cast<std::uint32_t>(static_cast<double>(value) * factor);
}

[[nodiscard]] pixel_rect clamp_rect(
    const std::int64_t x,
    const std::int64_t y,
    const std::int64_t width,
    const std::int64_t height,
    const chat_frame& frame) noexcept {
  const auto left = std::clamp<std::int64_t>(x, 0, frame.width);
  const auto top = std::clamp<std::int64_t>(y, 0, frame.height);
  const auto right = std::clamp<std::int64_t>(x + width, left, frame.width);
  const auto bottom = std::clamp<std::int64_t>(y + height, top, frame.height);
  return {
      .x = static_cast<std::uint32_t>(left),
      .y = static_cast<std::uint32_t>(top),
      .width = static_cast<std::uint32_t>(right - left),
      .height = static_cast<std::uint32_t>(bottom - top),
  };
}

[[nodiscard]] bool center_inside(
    const pixel_rect& inner,
    const pixel_rect& outer) noexcept {
  const auto center_x = inner.x + inner.width / 2;
  const auto center_y = inner.y + inner.height / 2;
  return center_x >= outer.x && center_x <= outer.x + outer.width &&
      center_y >= outer.y && center_y <= outer.y + outer.height;
}

[[nodiscard]] std::optional<pixel_rect> detect_active_tab(
    const chat_frame& frame) {
  const pixel_rect region{
      .x = 0,
      .y = 0,
      .width = std::max<std::uint32_t>(1, scaled_floor(frame.width, 0.35)),
      .height = std::max<std::uint32_t>(1, scaled_floor(frame.height, 0.09)),
  };
  const auto components = detail::connected_components(
      detail::red_hsv_mask(frame, region));
  std::optional<pixel_rect> best;
  for (const auto& component : components) {
    if (component.y >= static_cast<double>(frame.height) * 0.06 ||
        component.width < static_cast<double>(frame.width) * 0.0104167 ||
        component.width > std::max<std::uint32_t>(
            scaled_floor(frame.width, 0.104167),
            scaled_floor(frame.width, 0.16)) ||
        component.height < static_cast<double>(frame.height) * 0.0166667 ||
        component.height > std::max<std::uint32_t>(
            scaled_floor(frame.height, 0.0462963),
            scaled_floor(frame.height, 0.06)) ||
        component.area <= std::max<std::size_t>(
            static_cast<std::size_t>(std::lround(
                static_cast<double>(frame.width) * frame.height * 0.000168789)),
            static_cast<std::size_t>(
                static_cast<double>(frame.width) * frame.height * 0.00012))) {
      continue;
    }
    const pixel_rect candidate{
        .x = region.x + component.x,
        .y = region.y + component.y,
        .width = component.width,
        .height = component.height,
    };
    if (!best.has_value() ||
        candidate.width * candidate.height > best->width * best->height) {
      best = candidate;
    }
  }
  return best;
}

[[nodiscard]] std::vector<pixel_rect> merge_close_text(
    std::vector<pixel_rect> rectangles,
    const std::uint32_t maximum_gap) {
  std::ranges::sort(rectangles, {}, &pixel_rect::x);
  std::vector<pixel_rect> merged;
  for (const auto& rectangle : rectangles) {
    if (merged.empty()) {
      merged.push_back(rectangle);
      continue;
    }
    auto& last = merged.back();
    const auto last_center = last.y + last.height / 2;
    const auto current_center = rectangle.y + rectangle.height / 2;
    const auto center_distance = last_center > current_center
        ? last_center - current_center
        : current_center - last_center;
    const auto last_right = last.x + last.width;
    const auto gap = rectangle.x > last_right ? rectangle.x - last_right : 0;
    if (center_distance <= std::max(last.height, rectangle.height) &&
        gap <= maximum_gap) {
      const auto right = std::max(last_right, rectangle.x + rectangle.width);
      const auto bottom = std::max(last.y + last.height,
                                   rectangle.y + rectangle.height);
      const auto top = std::min(last.y, rectangle.y);
      last = {
          .x = last.x,
          .y = top,
          .width = right - last.x,
          .height = bottom - top,
      };
    } else {
      merged.push_back(rectangle);
    }
  }
  return merged;
}

[[nodiscard]] std::string canonical_tab_name(const std::size_t index) {
  static constexpr std::string_view kCanonicalNames[]{
      "Все", "Семья", "Фракция", "Департамент", "Репорт"};
  return index < std::size(kCanonicalNames)
      ? std::string(kCanonicalNames[index])
      : "Вкладка " + std::to_string(index + 1);
}

[[nodiscard]] pixel_chat_tab fallback_tab(
    const pixel_rect& active,
    const std::size_t index) {
  return {
      .id = {},
      .name = canonical_tab_name(index),
      .selected = true,
      .bounds = active,
  };
}

[[nodiscard]] std::vector<pixel_chat_tab> detect_tabs(
    const chat_frame& frame,
    const std::optional<pixel_rect>& active) {
  if (!active.has_value()) {
    return {};
  }
  const auto pad_y = std::max<std::uint32_t>(
      1, static_cast<std::uint32_t>(std::lround(
          static_cast<double>(frame.height) * 0.00277778)));
  const auto row = clamp_rect(
      0,
      static_cast<std::int64_t>(active->y) - pad_y,
      scaled_floor(frame.width, 0.35),
      static_cast<std::int64_t>(active->height) + pad_y * 2,
      frame);
  auto text_mask = detail::light_low_saturation_mask(
      frame, row, 115, 110);
  text_mask = detail::morphological_close(
      text_mask,
      std::max<std::uint32_t>(
          1, static_cast<std::uint32_t>(std::lround(
              static_cast<double>(frame.width) * 0.00208333))),
      std::max<std::uint32_t>(
          1, static_cast<std::uint32_t>(std::lround(
              static_cast<double>(frame.height) * 0.00185185))));

  std::vector<pixel_rect> text_rectangles;
  for (const auto& component : detail::connected_components(
           std::move(text_mask))) {
    if (component.width < static_cast<double>(frame.width) * 0.00416667 ||
        component.width > static_cast<double>(frame.width) * 0.0729167 ||
        component.height < static_cast<double>(frame.height) * 0.00648148 ||
        component.height > static_cast<double>(frame.height) * 0.0259259 ||
        component.area < static_cast<double>(frame.width) * frame.height *
            0.00000868056 ||
        component.x >= static_cast<double>(frame.width) * 0.25) {
      continue;
    }
    text_rectangles.push_back({
        .x = row.x + component.x,
        .y = row.y + component.y,
        .width = component.width,
        .height = component.height,
    });
  }

  const auto merged = merge_close_text(
      std::move(text_rectangles),
      std::max<std::uint32_t>(
          1, scaled_floor(frame.width, 0.00416667)));
  std::vector<pixel_chat_tab> tabs;
  for (const auto& text : merged) {
    const auto bounds = clamp_rect(
        static_cast<std::int64_t>(text.x) -
            scaled_floor(frame.width, 0.00625),
        static_cast<std::int64_t>(text.y) -
            scaled_floor(frame.height, 0.00740741),
        static_cast<std::int64_t>(text.width) +
            scaled_floor(frame.width, 0.0125),
        static_cast<std::int64_t>(text.height) +
            scaled_floor(frame.height, 0.0157407),
        frame);
    if (bounds.width == 0 || bounds.height == 0) {
      continue;
    }
    tabs.push_back({
        .id = {},
        .name = "Вкладка " + std::to_string(tabs.size() + 1),
        .selected = center_inside(bounds, *active),
        .bounds = bounds,
    });
  }
  if (tabs.empty()) {
    tabs.push_back(fallback_tab(*active, 0));
  } else if (std::ranges::none_of(tabs, &pixel_chat_tab::selected)) {
    tabs.push_back(fallback_tab(*active, tabs.size()));
  }
  std::ranges::sort(
      tabs,
      [](const pixel_chat_tab& left, const pixel_chat_tab& right) {
        return left.bounds.x < right.bounds.x;
      });
  for (std::size_t index = 0; index < tabs.size(); ++index) {
    tabs[index].id = std::to_string(index);
    tabs[index].name = canonical_tab_name(index);
  }
  return tabs;
}

[[nodiscard]] std::optional<std::pair<std::uint32_t, std::uint32_t>>
largest_horizontal_edge_span(
    const byte_image& edges,
    const std::uint32_t y,
    const std::uint32_t x_limit,
    const std::uint32_t maximum_gap) {
  std::vector<std::uint32_t> columns;
  const auto first_y = y > 2 ? y - 2 : 0;
  const auto last_y = std::min(edges.height, y + 3);
  for (std::uint32_t x = 0; x < x_limit; ++x) {
    bool present = false;
    for (auto sample_y = first_y; sample_y < last_y; ++sample_y) {
      if (edges.at(x, sample_y) != 0) {
        present = true;
        break;
      }
    }
    if (present) {
      columns.push_back(x);
    }
  }
  if (columns.empty()) {
    return std::nullopt;
  }
  std::vector<std::pair<std::uint32_t, std::uint32_t>> segments;
  auto start = columns.front();
  auto last = start;
  for (const auto column : columns | std::views::drop(1)) {
    if (column - last <= maximum_gap) {
      last = column;
      continue;
    }
    segments.emplace_back(start, last);
    start = column;
    last = column;
  }
  segments.emplace_back(start, last);
  return *std::ranges::max_element(
      segments,
      {},
      [](const auto& segment) { return segment.second - segment.first; });
}

[[nodiscard]] bool looks_like_input_body(
    const byte_image& gray,
    const byte_image& full_edges,
    const pixel_rect& rectangle) {
  if (rectangle.width <= 8 || rectangle.height <= 8) {
    return false;
  }
  const auto gray_crop = detail::crop(gray, rectangle);
  const auto inner = pixel_rect{
      .x = 4,
      .y = 4,
      .width = std::max<std::uint32_t>(1, gray_crop.width - 8),
      .height = std::max<std::uint32_t>(1, gray_crop.height - 8),
  };
  std::size_t bright = 0;
  for (std::uint32_t y = inner.y; y < inner.y + inner.height; ++y) {
    for (std::uint32_t x = inner.x; x < inner.x + inner.width; ++x) {
      if (gray_crop.at(x, y) > 130) {
        ++bright;
      }
    }
  }
  const auto bright_ratio = static_cast<double>(bright) /
      static_cast<double>(inner.width * inner.height);
  const auto edge_ratio = detail::nonzero_ratio(
      detail::crop(full_edges, rectangle));
  return bright_ratio <= 0.04 && edge_ratio <= 0.11;
}

[[nodiscard]] bool has_command_buttons_below(
    const chat_frame& frame,
    const pixel_rect& rectangle) {
  const auto bottom = rectangle.y + rectangle.height;
  const auto first_y = std::min(frame.height, bottom + 3);
  const auto last_y = std::min(
      frame.height,
      bottom + std::max<std::uint32_t>(
          52, scaled_floor(frame.height, 0.07)));
  const auto last_x = std::min(
      frame.width,
      rectangle.x + rectangle.width +
          std::max<std::uint32_t>(20, scaled_floor(frame.width, 0.04)));
  if (last_y <= first_y || last_x == 0) {
    return false;
  }
  const pixel_rect region{
      .x = 0,
      .y = first_y,
      .width = last_x,
      .height = last_y - first_y,
  };
  auto mask = detail::light_low_saturation_mask(frame, region, 110, 120);
  mask = detail::morphological_close(
      mask,
      std::max<std::uint32_t>(
          1, static_cast<std::uint32_t>(std::lround(
              static_cast<double>(frame.width) * 0.0046875))),
      std::max<std::uint32_t>(
          1, static_cast<std::uint32_t>(std::lround(
              static_cast<double>(frame.height) * 0.00277778))));
  std::vector<std::uint32_t> text_tops;
  for (const auto& component : detail::connected_components(std::move(mask))) {
    if (component.x >= static_cast<double>(frame.width) * 0.22 ||
        component.width < static_cast<double>(frame.width) * 0.00416667 ||
        component.width > static_cast<double>(frame.width) * 0.0442708 ||
        component.height < static_cast<double>(frame.height) * 0.00648148 ||
        component.height > static_cast<double>(frame.height) * 0.0259259 ||
        component.area < static_cast<double>(frame.width) * frame.height *
            0.0000072338) {
      continue;
    }
    text_tops.push_back(first_y + component.y);
  }
  if (text_tops.size() < 3) {
    return false;
  }
  const auto first_text = *std::ranges::min_element(text_tops);
  return first_text <= bottom +
      std::max<std::uint32_t>(30, scaled_floor(frame.height, 0.035));
}

[[nodiscard]] std::optional<pixel_rect> detect_input(
    const chat_frame& frame,
    const byte_image& gray,
    const byte_image& edges,
    const double minimum_row_score_factor) {
  const auto x_limit = std::max<std::uint32_t>(
      1, scaled_floor(frame.width, 0.30));
  const auto minimum_row_score = std::max<std::size_t>(
      1,
      scaled_floor(frame.width, minimum_row_score_factor));
  const auto maximum_span_gap = std::max<std::uint32_t>(
      1, scaled_floor(frame.width, 0.009375));
  std::vector<std::pair<std::uint32_t, std::uint32_t>> groups;
  std::optional<std::uint32_t> start;
  std::uint32_t last = 0;
  for (auto y = scaled_floor(frame.height, 0.20);
       y < scaled_floor(frame.height, 0.62);
       ++y) {
    std::size_t score = 0;
    for (std::uint32_t x = 0; x < x_limit; ++x) {
      if (edges.at(x, y) != 0) {
        ++score;
      }
    }
    if (score >= minimum_row_score) {
      if (!start.has_value()) {
        start = y;
      }
      last = y;
    } else if (start.has_value()) {
      groups.emplace_back(*start, last);
      start.reset();
    }
  }
  if (start.has_value()) {
    groups.emplace_back(*start, last);
  }

  const auto minimum_height = scaled_floor(frame.height, 0.028);
  const auto maximum_height = scaled_floor(frame.height, 0.078);
  std::vector<pixel_rect> candidates;
  for (std::size_t index = 0; index < groups.size(); ++index) {
    const auto top = (groups[index].first + groups[index].second) / 2;
    const auto top_span = largest_horizontal_edge_span(
        edges, top, x_limit, maximum_span_gap);
    if (!top_span.has_value()) {
      continue;
    }
    for (std::size_t bottom_index = index + 1;
         bottom_index < groups.size();
         ++bottom_index) {
      const auto bottom = (groups[bottom_index].first +
                           groups[bottom_index].second) / 2;
      const auto height = bottom - top + 1;
      if (height < minimum_height) {
        continue;
      }
      if (height > maximum_height) {
        break;
      }
      const auto bottom_span = largest_horizontal_edge_span(
          edges, bottom, x_limit, maximum_span_gap);
      if (!bottom_span.has_value()) {
        continue;
      }
      const auto left = std::min(top_span->first, bottom_span->first);
      const auto right = std::max(top_span->second, bottom_span->second);
      const auto width = right - left + 1;
      if (left >= static_cast<double>(frame.width) * 0.07 ||
          width < static_cast<double>(frame.width) * 0.18 ||
          width > static_cast<double>(frame.width) * 0.36 ||
          height < static_cast<double>(frame.height) * 0.025 ||
          height > static_cast<double>(frame.height) * 0.08) {
        continue;
      }
      const pixel_rect candidate{
          .x = left,
          .y = top,
          .width = width,
          .height = height,
      };
      if (looks_like_input_body(gray, edges, candidate) &&
          has_command_buttons_below(frame, candidate)) {
        candidates.push_back(candidate);
      }
    }
  }
  if (candidates.empty()) {
    return std::nullopt;
  }
  return *std::ranges::max_element(
      candidates,
      [](const pixel_rect& left, const pixel_rect& right) {
        if (left.y != right.y) {
          return left.y < right.y;
        }
        return left.width * left.height < right.width * right.height;
      });
}

[[nodiscard]] std::optional<pixel_rect> detect_input_contour_fallback(
    const chat_frame& frame,
    const byte_image& gray) {
  const pixel_rect region{
      .x = 0,
      .y = scaled_floor(frame.height, 0.20),
      .width = scaled_floor(frame.width, 0.40),
      .height = scaled_floor(frame.height, 0.65) -
          scaled_floor(frame.height, 0.20),
  };
  const auto region_gray = detail::crop(gray, region);
  auto closed = detail::canny_edges(region_gray, 20, 70);
  closed = detail::morphological_close(
      closed,
      std::max<std::uint32_t>(1, scaled_floor(frame.width, 0.00364583)),
      std::max<std::uint32_t>(1, scaled_floor(frame.height, 0.00277778)));
  const auto inset_x = std::max<std::uint32_t>(
      1, scaled_floor(frame.width, 0.0015625));
  const auto inset_y = std::max<std::uint32_t>(
      1, scaled_floor(frame.height, 0.00277778));
  std::vector<pixel_rect> candidates;
  for (const auto& component : detail::connected_components(
           std::move(closed))) {
    const pixel_rect candidate{
        .x = component.x,
        .y = region.y + component.y,
        .width = component.width,
        .height = component.height,
    };
    if (candidate.x >= static_cast<double>(frame.width) * 0.06 ||
        candidate.y < static_cast<double>(frame.height) * 0.38 ||
        candidate.width < static_cast<double>(frame.width) * 0.18 ||
        candidate.width > static_cast<double>(frame.width) * 0.35 ||
        candidate.height < static_cast<double>(frame.height) * 0.025 ||
        candidate.height > static_cast<double>(frame.height) * 0.08 ||
        candidate.width <= inset_x * 2 || candidate.height <= inset_y * 2) {
      continue;
    }
    const pixel_rect inner{
        .x = candidate.x + inset_x,
        .y = candidate.y + inset_y,
        .width = candidate.width - inset_x * 2,
        .height = candidate.height - inset_y * 2,
    };
    if (detail::mean(gray, inner) <= 95.0) {
      candidates.push_back(candidate);
    }
  }
  if (candidates.empty()) {
    return std::nullopt;
  }
  return *std::ranges::max_element(
      candidates,
      [](const pixel_rect& left, const pixel_rect& right) {
        if (left.y != right.y) {
          return left.y < right.y;
        }
        return left.width * left.height < right.width * right.height;
      });
}

}  // namespace

pixel_chat_detection majestic_chat_frame_detector::detect(
    const chat_frame& frame) {
  if (!frame.valid()) {
    return {.error = "chat_detector_frame_invalid"};
  }
  try {
    const auto gray = detail::grayscale(frame);
    const auto edges = detail::canny_edges(gray, 20, 70);
    auto input = detect_input(frame, gray, edges, 0.045);
    if (!input.has_value()) {
      input = detect_input(frame, gray, edges, 0.035);
    }
    if (!input.has_value()) {
      input = detect_input_contour_fallback(frame, gray);
    }
    auto tabs = detect_tabs(frame, detect_active_tab(frame));
    const auto selected = std::ranges::find_if(
        tabs, &pixel_chat_tab::selected);
    const auto selected_tab_id = selected == tabs.end()
        ? std::string{}
        : selected->id;
    return {
        .active = input.has_value(),
        .tabs = std::move(tabs),
        .selected_tab_id = selected_tab_id,
        .input_bounds = input,
    };
  } catch (const std::exception& error) {
    return {.error = std::string("chat_detector_failed:") + error.what()};
  } catch (...) {
    return {.error = "chat_detector_failed:unknown"};
  }
}

}  // namespace sonar::fishing::game_chat
