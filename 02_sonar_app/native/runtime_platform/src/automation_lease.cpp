#include "sonar/fishing/runtime_platform/automation_lease.h"

#include <utility>

namespace sonar::fishing::runtime_platform {

automation_lease::automation_lease(
    automation_lease_coordinator& owner) noexcept
    : owner_(&owner) {}

automation_lease::automation_lease(automation_lease&& other) noexcept
    : owner_(std::exchange(other.owner_, nullptr)) {}

automation_lease& automation_lease::operator=(
    automation_lease&& other) noexcept {
  if (this != &other) {
    release();
    owner_ = std::exchange(other.owner_, nullptr);
  }
  return *this;
}

automation_lease::~automation_lease() {
  release();
}

bool automation_lease::active() const noexcept {
  return owner_ != nullptr && owner_->owns(*this);
}

void automation_lease::release() noexcept {
  if (owner_ != nullptr) {
    owner_->release(*this);
    owner_ = nullptr;
  }
}

std::optional<automation_lease>
automation_lease_coordinator::try_acquire() noexcept {
  bool expected = false;
  if (!owned_.compare_exchange_strong(
          expected,
          true,
          std::memory_order_acq_rel,
          std::memory_order_acquire)) {
    return std::nullopt;
  }
  return automation_lease(*this);
}

bool automation_lease_coordinator::owned() const noexcept {
  return owned_.load(std::memory_order_acquire);
}

bool automation_lease_coordinator::chat_owned() const noexcept {
  return owned();
}

bool automation_lease_coordinator::owns(
    const automation_lease& lease) const noexcept {
  return lease.owner_ == this && owned();
}

void automation_lease_coordinator::release(
    const automation_lease& lease) noexcept {
  if (lease.owner_ == this) {
    bool expected = true;
    static_cast<void>(owned_.compare_exchange_strong(
        expected,
        false,
        std::memory_order_acq_rel,
        std::memory_order_acquire));
  }
}

}  // namespace sonar::fishing::runtime_platform
