#pragma once

#include <cstdint>
#include <span>
#include <string_view>

namespace sonar::fishing::automation_adapters::detail {

enum class visual_asset_kind : std::uint8_t {
  catch_button,
  inventory_surface,
  context_action,
  fish,
  food,
  garbage,
  hud_cue,
};

struct embedded_visual_asset final {
  std::string_view id;
  visual_asset_kind kind{visual_asset_kind::inventory_surface};
  std::string_view profile;
  std::uint32_t width{};
  std::uint32_t height{};
  std::string_view rgba_base64;
  std::string_view source_sha256;
};

// Product-owned descriptors generated once from the exact retired visual
// resources. Fish artwork is normalized to a transparent 64x64 canvas; small
// UI cues retain their original pixels. The descriptor table is compiled into
// Sonar.Engine.exe and is never loaded from a loose runtime asset.
[[nodiscard]] std::span<const embedded_visual_asset>
embedded_visual_assets() noexcept;

}  // namespace sonar::fishing::automation_adapters::detail
