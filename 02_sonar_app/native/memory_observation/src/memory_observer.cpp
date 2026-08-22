#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cwctype>
#include <cstring>
#include <limits>
#include <utility>

namespace sonar::fishing::memory_observation {
namespace {

[[nodiscard]] bool ascii_token(const std::string_view value) noexcept {
  return !value.empty() && value.size() <= 96U &&
      std::all_of(value.begin(), value.end(), [](const char character) {
        return character >= '!' && character <= '~';
      });
}

[[nodiscard]] bool sha256_text(const std::string_view value) noexcept {
  return value.size() == 64U &&
      std::all_of(value.begin(), value.end(), [](const char character) {
        return (character >= '0' && character <= '9') ||
            (character >= 'a' && character <= 'f') ||
            (character >= 'A' && character <= 'F');
      });
}

[[nodiscard]] char lower_hex(const char value) noexcept {
  return value >= 'A' && value <= 'F'
      ? static_cast<char>(value - 'A' + 'a')
      : value;
}

[[nodiscard]] bool equal_sha256(
    const std::string_view left,
    const std::string_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(left.begin(), left.end(), right.begin(), [](const char a, const char b) {
        return lower_hex(a) == lower_hex(b);
      });
}

[[nodiscard]] bool equal_image_name(
    const std::wstring_view left,
    const std::wstring_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(
          left.begin(),
          left.end(),
          right.begin(),
          [](const wchar_t a, const wchar_t b) {
            return std::towlower(a) == std::towlower(b);
          });
}

[[nodiscard]] std::size_t scalar_size(const scalar_type type) noexcept {
  switch (type) {
    case scalar_type::u8:
    case scalar_type::i8:
      return 1U;
    case scalar_type::u16_le:
    case scalar_type::i16_le:
      return 2U;
    case scalar_type::u32_le:
    case scalar_type::i32_le:
    case scalar_type::f32_le:
      return 4U;
    case scalar_type::f64_le:
      return 8U;
  }
  return 0U;
}

[[nodiscard]] capture_result fail(
    const capture_failure failure,
    std::string reason) {
  return capture_result{
      .snapshot = std::nullopt,
      .failure = failure,
      .reason = std::move(reason),
  };
}

[[nodiscard]] bool valid_expected_process(
    const expected_process& process) noexcept {
  if (!process.required) {
    return process.image_name.empty() && process.image_sha256.empty();
  }
  return !process.image_name.empty() && process.image_name.size() <= 260U &&
      sha256_text(process.image_sha256);
}

[[nodiscard]] bool valid_profile(
    const memory_observation_profile& profile) noexcept {
  if (!ascii_token(profile.profile_id) || profile.profile_revision == 0U ||
      !valid_expected_process(profile.game) ||
      !valid_expected_process(profile.webengine) ||
      !profile.game.required ||
      profile.inventory_candidates.size() > maximum_inventory_candidates ||
      profile.status_candidates.size() > maximum_status_candidates ||
      (profile.require_inventory &&
       (profile.minimum_inventory_votes == 0U ||
        profile.minimum_inventory_votes > profile.inventory_candidates.size())) ||
      !std::isfinite(profile.minimum_inventory_confidence) ||
      profile.minimum_inventory_confidence < 0.5 ||
      profile.minimum_inventory_confidence > 1.0 ||
      !std::isfinite(profile.reeling.maximum_distance) ||
      profile.reeling.maximum_distance <= 0.0) {
    return false;
  }
  if ((profile.require_chat || profile.require_player_status) &&
      !profile.webengine.required && profile.status_candidates.empty()) {
    return false;
  }
  if (profile.require_inventory && profile.inventory_candidates.empty()) {
    return false;
  }
  return true;
}

struct plan_inventory final {
  const read_region* reeling_player{};
  const read_region* reeling_fish{};
  const read_region* reeling_fish_identity{};
  const read_region* player_status_window{};
  const read_region* chat_state_window{};
  std::vector<const read_region*> inventory;
  std::vector<const read_region*> status;
  std::size_t total_bytes{};
  bool uses_webengine{};
};

[[nodiscard]] std::optional<plan_inventory> validate_plan(
    const memory_observation_profile& profile,
    const capture_plan& plan) {
  if (plan.sequence == 0U || plan.captured_at_steady_ns == 0U ||
      plan.game_process_id == 0U || plan.regions.empty() ||
      plan.regions.size() > maximum_read_regions ||
      plan.expected_game_generation.process_id != plan.game_process_id ||
      plan.expected_game_generation.creation_time_filetime_100ns == 0U) {
    return std::nullopt;
  }
  plan_inventory result;
  result.inventory.resize(profile.inventory_candidates.size(), nullptr);
  result.status.resize(profile.status_candidates.size(), nullptr);
  for (const auto& region : plan.regions) {
    if (region.address == 0U || region.size == 0U ||
        region.size > maximum_read_region_bytes ||
        region.address > std::numeric_limits<std::uintptr_t>::max() -
                (region.size - 1U) ||
        result.total_bytes > maximum_capture_bytes - region.size) {
      return std::nullopt;
    }
    result.total_bytes += region.size;
    if (region.role == process_role::webengine) {
      result.uses_webengine = true;
    }
    switch (region.kind) {
      case evidence_region_kind::reeling_player:
        if (result.reeling_player != nullptr || region.role != process_role::game ||
            region.slot != 0U) {
          return std::nullopt;
        }
        result.reeling_player = &region;
        break;
      case evidence_region_kind::reeling_fish:
        if (result.reeling_fish != nullptr || region.role != process_role::game ||
            region.slot != 0U) {
          return std::nullopt;
        }
        result.reeling_fish = &region;
        break;
      case evidence_region_kind::reeling_fish_identity:
        if (result.reeling_fish_identity != nullptr ||
            region.role != process_role::game || region.slot != 0U ||
            region.size != sizeof(std::uint32_t)) {
          return std::nullopt;
        }
        result.reeling_fish_identity = &region;
        break;
      case evidence_region_kind::inventory_candidate:
        if (region.role != process_role::game || region.size != 1U ||
            region.slot >= result.inventory.size() ||
            result.inventory[region.slot] != nullptr) {
          return std::nullopt;
        }
        result.inventory[region.slot] = &region;
        break;
      case evidence_region_kind::player_status_candidate:
        if (region.slot >= result.status.size() ||
            result.status[region.slot] != nullptr ||
            region.size != scalar_size(profile.status_candidates[region.slot].type)) {
          return std::nullopt;
        }
        result.status[region.slot] = &region;
        break;
      case evidence_region_kind::player_status_window:
        if (result.player_status_window != nullptr ||
            region.role != process_role::webengine || region.slot != 0U) {
          return std::nullopt;
        }
        result.player_status_window = &region;
        break;
      case evidence_region_kind::chat_state_window:
        if (result.chat_state_window != nullptr ||
            region.role != process_role::webengine || region.slot != 0U) {
          return std::nullopt;
        }
        result.chat_state_window = &region;
        break;
    }
  }
  if (profile.require_reeling &&
      (result.reeling_player == nullptr || result.reeling_fish == nullptr)) {
    return std::nullopt;
  }
  if (profile.require_inventory &&
      std::any_of(result.inventory.begin(), result.inventory.end(), [](const auto* item) {
        return item == nullptr;
      })) {
    return std::nullopt;
  }
  if (!profile.status_candidates.empty() &&
      std::any_of(result.status.begin(), result.status.end(), [](const auto* item) {
        return item == nullptr;
      })) {
    return std::nullopt;
  }
  if (profile.require_player_status && result.player_status_window == nullptr &&
      profile.status_candidates.empty()) {
    return std::nullopt;
  }
  if (profile.require_chat && result.chat_state_window == nullptr) {
    return std::nullopt;
  }
  if (result.uses_webengine &&
      (!profile.webengine.required || plan.webengine_process_id == 0U ||
       !plan.expected_webengine_generation.has_value() ||
       plan.expected_webengine_generation->process_id !=
           plan.webengine_process_id ||
       plan.expected_webengine_generation->creation_time_filetime_100ns == 0U)) {
    return std::nullopt;
  }
  if (!result.uses_webengine && plan.expected_webengine_generation.has_value()) {
    return std::nullopt;
  }
  return result;
}

[[nodiscard]] bool identity_matches(
    const process_identity& observed,
    const process_role role,
    const expected_process& expected,
    const sonar::platform::windows::process_generation&
        expected_generation) noexcept {
  return observed.role == role &&
      observed.generation == expected_generation &&
      equal_image_name(observed.image_name, expected.image_name);
}

}  // namespace

bool capture_result::ready() const noexcept {
  return failure == capture_failure::none && snapshot.has_value();
}

std::unique_ptr<readonly_memory_session> disabled_memory_connector::connect(
    const process_role role,
    const std::uint32_t process_id,
    std::string& reason) noexcept {
  static_cast<void>(role);
  static_cast<void>(process_id);
  reason = "memory_observation_disabled";
  return nullptr;
}

memory_observer::memory_observer(memory_connector& connector) noexcept
    : connector_(connector) {}

capture_result memory_observer::capture(
    const memory_observation_profile& profile,
    const capture_plan& plan) noexcept {
  try {
    if (!valid_profile(profile)) {
      return fail(capture_failure::invalid_profile, "memory_profile_invalid");
    }
    const auto inventory = validate_plan(profile, plan);
    if (!inventory.has_value()) {
      return fail(capture_failure::invalid_plan, "memory_capture_plan_invalid");
    }
    if (plan.sequence <= last_sequence_) {
      return fail(capture_failure::sequence_replayed, "memory_sequence_replayed");
    }
    if (!inventory->uses_webengine) {
      webengine_session_.reset();
    }

    if (game_session_ != nullptr &&
        game_session_->identity().generation !=
            plan.expected_game_generation) {
      game_session_.reset();
    }
    std::string connector_reason;
    if (game_session_ == nullptr) {
      game_session_ = connector_.connect(
          process_role::game, plan.game_process_id, connector_reason);
    }
    if (!game_session_) {
      return fail(
          connector_reason == "memory_observation_disabled"
              ? capture_failure::disabled
              : capture_failure::process_unavailable,
          connector_reason.empty() ? "game_process_unavailable" : connector_reason);
    }
    if (!identity_matches(
            game_session_->identity(),
            process_role::game,
            profile.game,
            plan.expected_game_generation)) {
      game_session_.reset();
      return fail(
          capture_failure::process_identity_mismatch,
          "game_process_identity_mismatch");
    }
    if (!equal_sha256(
            game_session_->identity().image_sha256,
            profile.game.image_sha256)) {
      game_session_.reset();
      return fail(capture_failure::profile_hash_mismatch, "game_profile_hash_mismatch");
    }

    if (inventory->uses_webengine) {
      if (webengine_session_ != nullptr &&
          webengine_session_->identity().generation !=
              *plan.expected_webengine_generation) {
        webengine_session_.reset();
      }
      connector_reason.clear();
      if (webengine_session_ == nullptr) {
        webengine_session_ = connector_.connect(
            process_role::webengine,
            plan.webengine_process_id,
            connector_reason);
      }
      if (!webengine_session_) {
        return fail(
            connector_reason == "memory_observation_disabled"
                ? capture_failure::disabled
                : capture_failure::process_unavailable,
            connector_reason.empty()
                ? "webengine_process_unavailable"
                : connector_reason);
      }
      if (!identity_matches(
              webengine_session_->identity(),
              process_role::webengine,
              profile.webengine,
              *plan.expected_webengine_generation)) {
        webengine_session_.reset();
        return fail(
            capture_failure::process_identity_mismatch,
            "webengine_process_identity_mismatch");
      }
      if (!equal_sha256(
              webengine_session_->identity().image_sha256,
              profile.webengine.image_sha256)) {
        webengine_session_.reset();
        return fail(
            capture_failure::profile_hash_mismatch,
            "webengine_profile_hash_mismatch");
      }
    }

    std::vector<std::byte> reeling_player;
    std::vector<std::byte> reeling_fish;
    std::vector<std::byte> reeling_fish_identity;
    std::vector<std::byte> inventory_samples(
        profile.inventory_candidates.size());
    std::vector<std::vector<std::byte>> status_samples(
        profile.status_candidates.size());
    std::vector<std::byte> status_window;
    std::vector<std::byte> chat_window;

    const auto read = [&](const read_region& region,
                          std::vector<std::byte>& destination) {
      destination.resize(region.size);
      auto* session = region.role == process_role::game
          ? game_session_.get()
          : webengine_session_.get();
      return session != nullptr &&
          session->read_exact(region.address, destination);
    };
    if (inventory->reeling_player != nullptr &&
        !read(*inventory->reeling_player, reeling_player)) {
      return fail(capture_failure::read_failed, "reeling_player_read_failed");
    }
    if (inventory->reeling_fish != nullptr &&
        !read(*inventory->reeling_fish, reeling_fish)) {
      return fail(capture_failure::read_failed, "reeling_fish_read_failed");
    }
    if (inventory->reeling_fish_identity != nullptr &&
        !read(*inventory->reeling_fish_identity, reeling_fish_identity)) {
      return fail(
          capture_failure::read_failed,
          "reeling_fish_identity_read_failed");
    }
    for (std::size_t index = 0U; index < inventory->inventory.size(); ++index) {
      if (inventory->inventory[index] == nullptr) {
        continue;
      }
      std::vector<std::byte> sample;
      if (!read(*inventory->inventory[index], sample) || sample.size() != 1U) {
        return fail(capture_failure::read_failed, "inventory_read_failed");
      }
      inventory_samples[index] = sample.front();
    }
    for (std::size_t index = 0U; index < inventory->status.size(); ++index) {
      if (inventory->status[index] != nullptr &&
          !read(*inventory->status[index], status_samples[index])) {
        return fail(capture_failure::read_failed, "player_status_read_failed");
      }
    }
    if (inventory->player_status_window != nullptr &&
        !read(*inventory->player_status_window, status_window)) {
      return fail(capture_failure::read_failed, "player_status_window_read_failed");
    }
    if (inventory->chat_state_window != nullptr &&
        !read(*inventory->chat_state_window, chat_window)) {
      return fail(capture_failure::read_failed, "chat_state_window_read_failed");
    }

    if (!game_session_->generation_current() ||
        (webengine_session_ != nullptr &&
         !webengine_session_->generation_current())) {
      game_session_.reset();
      webengine_session_.reset();
      return fail(capture_failure::process_changed, "memory_process_generation_changed");
    }

    std::optional<reeling_evidence> reeling;
    if (!reeling_player.empty() || !reeling_fish.empty()) {
      if (!reeling_fish_identity.empty()) {
        std::uint32_t observed_hash{};
        std::memcpy(
            &observed_hash,
            reeling_fish_identity.data(),
            sizeof(observed_hash));
        if (observed_hash != profile.reeling.expected_fish_model_hash ||
            profile.reeling.fish_model_hash_offset > reeling_fish.size() ||
            sizeof(observed_hash) >
                reeling_fish.size() - profile.reeling.fish_model_hash_offset) {
          return fail(
              capture_failure::decode_failed,
              "reeling_fish_identity_changed");
        }
        // The legacy model hash lives behind an archetype pointer, while the
        // decoder consumes one bounded entity projection. Copy only the
        // independently re-read verified value into that projection.
        std::memcpy(
            reeling_fish.data() + profile.reeling.fish_model_hash_offset,
            &observed_hash,
            sizeof(observed_hash));
      }
      reeling = decode_reeling_evidence(
          reeling_player, reeling_fish, profile.reeling);
    }
    std::optional<inventory_evidence> inventory_evidence_value;
    if (!inventory_samples.empty()) {
      inventory_evidence_value = decode_inventory_evidence(
          inventory_samples,
          profile.inventory_candidates,
          profile.minimum_inventory_votes,
          profile.minimum_inventory_confidence);
    }
    const auto player_status = decode_player_status_evidence(
        status_samples, profile.status_candidates, status_window);
    std::optional<chat_evidence> chat;
    if (!chat_window.empty()) {
      chat = decode_chat_evidence(chat_window);
    }

    if ((profile.require_reeling && !reeling.has_value()) ||
        (profile.require_inventory && !inventory_evidence_value.has_value()) ||
        (profile.require_player_status && !player_status.has_value()) ||
        (profile.require_chat && !chat.has_value())) {
      return fail(capture_failure::decode_failed, "memory_evidence_decode_failed");
    }

    coherent_memory_snapshot snapshot{
        .sequence = plan.sequence,
        .captured_at_steady_ns = plan.captured_at_steady_ns,
        .profile_id = profile.profile_id,
        .profile_revision = profile.profile_revision,
        .game_generation = game_session_->identity().generation,
        .reeling = std::move(reeling),
        .inventory = std::move(inventory_evidence_value),
        .player_status = player_status,
        .chat = std::move(chat),
    };
    if (webengine_session_ != nullptr) {
      snapshot.webengine_generation =
          webengine_session_->identity().generation;
    }
    last_sequence_ = plan.sequence;
    return capture_result{
        .snapshot = std::move(snapshot),
        .failure = capture_failure::none,
        .reason = "ready",
    };
  } catch (...) {
    return fail(capture_failure::decode_failed, "memory_observation_exception");
  }
}

std::string_view to_string(const capture_failure value) noexcept {
  switch (value) {
    case capture_failure::none:
      return "none";
    case capture_failure::disabled:
      return "disabled";
    case capture_failure::invalid_profile:
      return "invalid_profile";
    case capture_failure::invalid_plan:
      return "invalid_plan";
    case capture_failure::sequence_replayed:
      return "sequence_replayed";
    case capture_failure::process_unavailable:
      return "process_unavailable";
    case capture_failure::process_identity_mismatch:
      return "process_identity_mismatch";
    case capture_failure::profile_hash_mismatch:
      return "profile_hash_mismatch";
    case capture_failure::read_failed:
      return "read_failed";
    case capture_failure::process_changed:
      return "process_changed";
    case capture_failure::decode_failed:
      return "decode_failed";
  }
  return "unknown";
}

}  // namespace sonar::fishing::memory_observation
