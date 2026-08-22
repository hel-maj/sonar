#pragma once

#include <atomic>
#include <optional>

namespace sonar::fishing::runtime_platform {

class automation_lease_coordinator;

class automation_lease final {
 public:
  automation_lease(const automation_lease&) = delete;
  automation_lease& operator=(const automation_lease&) = delete;
  automation_lease(automation_lease&& other) noexcept;
  automation_lease& operator=(automation_lease&& other) noexcept;
  ~automation_lease();

  [[nodiscard]] bool active() const noexcept;

 private:
  friend class automation_lease_coordinator;
  explicit automation_lease(automation_lease_coordinator& owner) noexcept;
  void release() noexcept;

  automation_lease_coordinator* owner_{};
};

class automation_lease_coordinator final {
 public:
  [[nodiscard]] std::optional<automation_lease> try_acquire() noexcept;
  [[nodiscard]] bool owned() const noexcept;
  // Compatibility projection for the existing E19 public contract. All
  // automation capabilities still share this single coordinator instance.
  [[nodiscard]] bool chat_owned() const noexcept;
  [[nodiscard]] bool owns(const automation_lease& lease) const noexcept;

 private:
  friend class automation_lease;
  void release(const automation_lease& lease) noexcept;

  std::atomic_bool owned_{false};
};

}  // namespace sonar::fishing::runtime_platform
