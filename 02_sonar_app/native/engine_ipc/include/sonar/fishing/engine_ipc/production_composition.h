#pragma once

#include <cstddef>
#include <cstdint>
#include <deque>
#include <memory>
#include <mutex>
#include <optional>
#include <stop_token>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#include "sonar/fishing/catch_observation/catch_observation.h"
#include "sonar/fishing/equipment_recovery/equipment_recovery.h"
#include "sonar/fishing/fishing_episode/fishing_episode.h"
#include "sonar/fishing/engine_ipc/production_session_loop.h"
#include "sonar/fishing/session_statistics/session_statistics.h"

namespace sonar::fishing::engine_ipc {

enum class production_phase : std::uint8_t {
  idle,
  fishing,
  catch_processing,
  inventory,
  maintenance,
  stopping,
};

inline constexpr std::size_t maximum_pending_production_notifications = 64U;

struct production_player_status_notification final {
  std::optional<int> food;
  std::optional<int> water;
  std::optional<int> health;
  std::optional<double> inventory_weight;
  std::optional<double> inventory_weight_max;
  std::optional<double> backpack_weight;
  std::optional<double> backpack_weight_max;
};

struct production_catch_notification final {
  std::string fish_name;
  std::optional<double> weight_kg;
  std::optional<std::string> quality_text;
  bool released{};
  session_statistics::SessionTotals totals{};
  std::optional<std::uint64_t> xp_current;
  std::optional<std::uint64_t> xp_total;
};

struct production_meal_recovered_notification final {
  std::size_t affected_count{};
  std::optional<production_player_status_notification> player_status;
};

struct production_inventory_full_notification final {};
struct production_bait_tired_notification final {};

struct production_focus_lost_notification final {
  std::string reason;
};

using production_notification_event = std::variant<
    production_catch_notification,
    production_meal_recovered_notification,
    production_inventory_full_notification,
    production_player_status_notification,
    production_bait_tired_notification,
    production_focus_lost_notification>;

class production_session_progress_sink {
 public:
  virtual ~production_session_progress_sink() = default;
  virtual void publish_phase(
      production_phase phase,
      std::string detected_stage) noexcept = 0;
  virtual void record_catch(
      const catch_observation::CatchObservation& observation,
      bool kept) noexcept = 0;
  virtual void publish_tackle(
      const equipment_recovery::TackleCounts& counts) noexcept = 0;
  virtual void publish_notification(
      production_notification_event notification) noexcept = 0;
};

struct production_capability_snapshot final {
  bool stage_detection_linked{};
  bool memory_observation_linked{};
  bool fishing_episode_linked{};
  bool inventory_store_linked{};
  bool maintenance_episode_linked{};
  bool catch_observation_linked{};
  bool observation_adapters_enabled{};
  bool mutation_adapters_enabled{};
  bool session_prepared{};
  bool operation_running{};
  bool operation_completed{};
  bool last_operation_ok{};
  std::string last_operation_reason;
  std::uint64_t progress_revision{};
  production_phase phase{production_phase::idle};
  std::string detected_stage;
  std::size_t cycles_completed{};
  std::size_t catches_processed{};
  std::size_t inventory_episodes_completed{};
  std::size_t maintenance_episodes_completed{};
  std::size_t pending_notification_count{};
  std::uint64_t dropped_notification_count{};
  session_statistics::SessionStatisticsSnapshot statistics;

  [[nodiscard]] bool complete_native_graph() const noexcept;
  [[nodiscard]] bool ready_for_live_automation() const noexcept;
};

struct production_capability_admission final {
  bool accepted{};
  std::string reason;
};

// One product-owned coarse operation seam. Implementations keep observation,
// decision, immediate final revalidation and mutation inside the Engine. The
// Host never receives a frame, address, detector step or individual input RPC.
class production_automation_session {
 public:
  virtual ~production_automation_session() = default;
  [[nodiscard]] virtual production_session_result run(
      const production_session_request& request,
      std::stop_token stop_token,
      production_session_progress_sink& progress) = 0;
  [[nodiscard]] virtual bool refresh_entitlement_expiry(
      std::uint64_t admitted_entitlement_generation,
      std::int64_t expires_unix_seconds) noexcept = 0;
};

struct production_automation_session_admission final {
  std::unique_ptr<production_automation_session> session;
  std::string reason;
};

// Tests inject a fixture-only factory. The shipping factory is inert until
// prepare() and then resolves the exact GTA5.exe process/window generation,
// attaches the bounded target guard and constructs capture/input adapters.
class production_automation_session_factory {
 public:
  virtual ~production_automation_session_factory() = default;
  [[nodiscard]] virtual production_automation_session_admission prepare()
      noexcept = 0;
};

[[nodiscard]] std::unique_ptr<production_automation_session_factory>
make_windows_production_automation_session_factory();

// Owns the production coarse capability graph. Construction is inert. A
// production Start request must first pass pure authority/settings/entitlement
// lifecycle admission, then prepare_session() may touch only the selected game
// process/window, and start_session() launches one cancellable whole episode.
class production_capability_composition final
    : private production_session_progress_sink {
 public:
  production_capability_composition();
  explicit production_capability_composition(
      std::unique_ptr<production_automation_session_factory> factory);
  ~production_capability_composition();

  production_capability_composition(
      const production_capability_composition&) = delete;
  production_capability_composition& operator=(
      const production_capability_composition&) = delete;

  [[nodiscard]] production_capability_snapshot snapshot() const;
  [[nodiscard]] std::vector<production_notification_event>
  take_pending_notifications() noexcept;

  [[nodiscard]] production_capability_admission prepare_session(
      runtime_settings::RuntimeSettingsSnapshot settings,
      std::uint64_t entitlement_generation,
      std::int64_t entitlement_expires_unix_seconds) noexcept;
  [[nodiscard]] production_capability_admission start_session() noexcept;
  [[nodiscard]] production_capability_admission refresh_entitlement_expiry(
      std::uint64_t admitted_entitlement_generation,
      std::int64_t expires_unix_seconds) noexcept;

  void stop() noexcept;

  [[nodiscard]] catch_observation::CatchObservation interpret_catch(
      const catch_observation::RawCatchText& raw) const;

 private:
  void publish_phase(
      production_phase phase,
      std::string detected_stage) noexcept override;
  void record_catch(
      const catch_observation::CatchObservation& observation,
      bool kept) noexcept override;
  void publish_tackle(
      const equipment_recovery::TackleCounts& counts) noexcept override;
  void publish_notification(
      production_notification_event notification) noexcept override;
  void enqueue_notification(
      production_notification_event notification) noexcept;
  void advance_progress_revision() noexcept;

  std::unique_ptr<production_automation_session_factory> factory_;
  std::unique_ptr<production_automation_session> session_;
  std::jthread operation_;
  mutable std::mutex state_gate_;
  runtime_settings::RuntimeSettingsSnapshot prepared_settings_;
  std::uint64_t prepared_entitlement_generation_{};
  std::int64_t prepared_entitlement_expires_unix_seconds_{};
  std::uint64_t lifecycle_revision_{};
  bool session_prepared_{};
  bool operation_running_{};
  bool operation_completed_{};
  bool last_operation_ok_{};
  std::string last_operation_reason_;
  std::uint64_t progress_revision_{};
  production_phase phase_{production_phase::idle};
  std::string detected_stage_;
  production_session_result last_result_;
  std::deque<production_notification_event> pending_notifications_;
  std::uint64_t dropped_notification_count_{};
  session_statistics::SessionStatistics statistics_{
      session_statistics::DefaultPriceCatalog()};
};

}  // namespace sonar::fishing::engine_ipc
