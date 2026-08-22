#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <stop_token>
#include <string>
#include <vector>

#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

namespace sonar::fishing::inventory_store {

enum class inventory_surface : std::uint8_t {
  unknown = 0,
  gameplay = 1,
  game_menu = 2,
  inventory = 3,
  item_context_menu = 4,
};

enum class inventory_compartment : std::uint8_t {
  player_inventory = 0,
  backpack = 1,
};

struct inventory_item_observation final {
  std::string instance_id;
  std::string item_id;
  std::string title;
  inventory_compartment compartment{inventory_compartment::player_inventory};
  double confidence{};
  stage_detection::normalized_rect bounds;
};

struct inventory_context_action_observation final {
  std::string item_instance_id;
  double confidence{};
  stage_detection::normalized_rect bounds;
};

struct inventory_observation final {
  std::uint64_t sequence{};
  inventory_surface surface{inventory_surface::unknown};
  stage_detection::observed_fishing_stage fishing_stage{
      stage_detection::observed_fishing_stage::none};
  bool catch_screen_visible{};
  std::vector<inventory_item_observation> items;
  std::optional<inventory_context_action_observation> remove_action;
  std::string error;
};

struct inventory_store_request final {
  std::string inventory_hotkey{"i"};
  std::string fishing_entry_hotkey{"e"};
  std::vector<std::string> fish_to_store;
  bool open_inventory{true};
  bool resume_fishing{true};
};

enum class inventory_intent_kind : std::uint8_t {
  activate_window = 0,
  release_all_keys = 1,
  press_key = 2,
  right_click_item = 3,
  click_context_action = 4,
  pause = 5,
  use_inventory_item = 6,
  move_backpack_item = 7,
  discard_inventory_item = 8,
  stop_automation = 9,
  exit_game = 10,
  shutdown_pc = 11,
};

struct inventory_mutation_intent final {
  inventory_intent_kind kind{inventory_intent_kind::pause};
  std::uint64_t expected_observation_sequence{};
  std::string key;
  std::string item_instance_id;
  stage_detection::normalized_rect target_bounds;
  std::size_t packet_count{};
  std::size_t delay_milliseconds{};
};

struct inventory_mutation_result final {
  bool applied{};
  std::string reason;

  [[nodiscard]] static inventory_mutation_result accepted();
  [[nodiscard]] static inventory_mutation_result rejected(std::string reason);
};

class inventory_observer {
 public:
  virtual ~inventory_observer() = default;
  [[nodiscard]] virtual inventory_observation observe(
      std::stop_token stop_token) = 0;
};

// This is the immediate final boundary for every intent. A future live adapter
// must hold the shared exclusive Engine input lease and revalidate entitlement,
// settings revision, lifecycle, process/window generation, foreground identity
// and Common packet budget against expected_observation_sequence immediately
// before the matching platform mutation. Earlier authorization is not reusable.
class inventory_mutation_port {
 public:
  virtual ~inventory_mutation_port() = default;
  [[nodiscard]] virtual inventory_mutation_result apply(
      const inventory_mutation_intent& intent,
      std::stop_token stop_token) = 0;
};

// A coarse Engine-owned operation executes inside the same inventory session
// as E15. It can observe, delay and submit atomic intents, but it cannot bypass
// the exact-sequence mutation port or own a second platform adapter/lease.
class inventory_episode_context {
 public:
  virtual ~inventory_episode_context() = default;
  [[nodiscard]] virtual const inventory_observation& current() const noexcept = 0;
  [[nodiscard]] virtual bool refresh() = 0;
  [[nodiscard]] virtual bool mutate(inventory_mutation_intent intent) = 0;
  [[nodiscard]] virtual bool wait(std::size_t milliseconds) = 0;
  [[nodiscard]] virtual bool reject(std::string reason) = 0;
  virtual void prevent_resume() noexcept = 0;
};

enum class inventory_operation_preflight_disposition : std::uint8_t {
  proceed = 0,
  complete = 1,
  reject = 2,
};

struct inventory_operation_preflight_result final {
  inventory_operation_preflight_disposition disposition{
      inventory_operation_preflight_disposition::proceed};
  std::string reason;
};

class inventory_episode_operation {
 public:
  virtual ~inventory_episode_operation() = default;
  [[nodiscard]] virtual inventory_operation_preflight_result preflight(
      const inventory_observation& observation,
      std::stop_token stop_token);
  [[nodiscard]] virtual bool execute(
      inventory_episode_context& context,
      std::stop_token stop_token) = 0;
};

struct inventory_store_result final {
  bool ok{};
  std::string reason;
  std::size_t stored_count{};
  bool recovery_attempted{};
  bool recovery_completed{};
  inventory_observation observation;
};

class inventory_store_episode_runner final {
 public:
  [[nodiscard]] inventory_store_result run(
      const inventory_store_request& request,
      inventory_observer& observer,
      inventory_mutation_port& mutation,
      std::stop_token stop_token = {}) const;

  [[nodiscard]] inventory_store_result run_operation(
      const inventory_store_request& request,
      inventory_episode_operation& operation,
      inventory_observer& observer,
      inventory_mutation_port& mutation,
      std::stop_token stop_token = {}) const;
};

// Shipping/offline composition remains fail closed. Tests inject a recording
// port; no platform mutation implementation is connected by this slice.
class disabled_inventory_mutation_port final : public inventory_mutation_port {
 public:
  [[nodiscard]] inventory_mutation_result apply(
      const inventory_mutation_intent& intent,
      std::stop_token stop_token) override;
};

[[nodiscard]] const char* inventory_intent_key(
    inventory_intent_kind kind) noexcept;

}  // namespace sonar::fishing::inventory_store
