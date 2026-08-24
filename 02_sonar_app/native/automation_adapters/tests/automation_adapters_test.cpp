#include "sonar/fishing/automation_adapters/fishing_adapters.h"

#include "../src/memory_capture_retry.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>
#include <wincodec.h>
#include <wrl/client.h>

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifndef SONAR_FISHING_BUBBLE_FIXTURE
#error SONAR_FISHING_BUBBLE_FIXTURE is required
#endif

namespace {

using Microsoft::WRL::ComPtr;
namespace adapters = sonar::fishing::automation_adapters;
namespace episode = sonar::fishing::fishing_episode;
namespace platform = sonar::fishing::runtime_platform;

struct bgr24_image final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t stride{};
  std::vector<std::uint8_t> pixels;
};

struct fixture_case final {
  std::filesystem::path image;
  std::uintmax_t bytes{};
  std::uint32_t width{};
  std::uint32_t height{};
  bool cast_ready{};
  episode::hook_cue hook{episode::hook_cue::none};
  bool catch_visible{};
};

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

void require_hresult(const HRESULT result, const std::string_view reason) {
  if (FAILED(result)) {
    throw std::runtime_error(
        std::string(reason) + ":" + std::to_string(result));
  }
}

[[nodiscard]] std::vector<std::string> split_tabs(const std::string& line) {
  std::vector<std::string> fields;
  std::size_t start = 0U;
  while (true) {
    const auto separator = line.find('\t', start);
    if (separator == std::string::npos) {
      fields.push_back(line.substr(start));
      return fields;
    }
    fields.push_back(line.substr(start, separator - start));
    start = separator + 1U;
  }
}

[[nodiscard]] bool parse_bool(const std::string_view value) {
  if (value == "true") {
    return true;
  }
  if (value == "false") {
    return false;
  }
  throw std::runtime_error("automation_fixture_boolean_invalid");
}

[[nodiscard]] episode::hook_cue parse_hook(const std::string_view value) {
  if (value == "none") {
    return episode::hook_cue::none;
  }
  if (value == "red") {
    return episode::hook_cue::red;
  }
  throw std::runtime_error("automation_fixture_hook_invalid");
}

[[nodiscard]] std::vector<fixture_case> load_manifest() {
  const std::filesystem::path manifest = SONAR_FISHING_AUTOMATION_FIXTURE;
  std::ifstream stream(manifest);
  require(stream.good(), "automation_fixture_manifest_missing");
  std::string line;
  require(static_cast<bool>(std::getline(stream, line)),
      "automation_fixture_manifest_empty");
  require(
      line == "file\tsha256\tbytes\twidth\theight\tcast_ready\thook\tcatch_visible",
      "automation_fixture_manifest_header_changed");
  std::vector<fixture_case> result;
  while (std::getline(stream, line)) {
    if (line.empty()) {
      continue;
    }
    const auto fields = split_tabs(line);
    require(fields.size() == 8U, "automation_fixture_manifest_row_invalid");
    require(fields[1].size() == 64U,
        "automation_fixture_manifest_hash_invalid");
    result.push_back({
        .image = manifest.parent_path() / fields[0],
        .bytes = static_cast<std::uintmax_t>(std::stoull(fields[2])),
        .width = static_cast<std::uint32_t>(std::stoul(fields[3])),
        .height = static_cast<std::uint32_t>(std::stoul(fields[4])),
        .cast_ready = parse_bool(fields[5]),
        .hook = parse_hook(fields[6]),
        .catch_visible = parse_bool(fields[7]),
    });
  }
  require(result.size() == 5U, "automation_fixture_manifest_count_changed");
  return result;
}

class com_apartment final {
 public:
  com_apartment() {
    require_hresult(
        CoInitializeEx(nullptr, COINIT_MULTITHREADED),
        "automation_fixture_com_initialize_failed");
    initialized_ = true;
  }

  ~com_apartment() {
    if (initialized_) {
      CoUninitialize();
    }
  }

  com_apartment(const com_apartment&) = delete;
  com_apartment& operator=(const com_apartment&) = delete;

 private:
  bool initialized_{};
};

[[nodiscard]] bgr24_image load_bgr24(
    IWICImagingFactory& factory,
    const std::filesystem::path& path) {
  ComPtr<IWICBitmapDecoder> decoder;
  require_hresult(
      factory.CreateDecoderFromFilename(
          path.c_str(),
          nullptr,
          GENERIC_READ,
          WICDecodeMetadataCacheOnLoad,
          decoder.GetAddressOf()),
      "automation_fixture_open_failed");
  ComPtr<IWICBitmapFrameDecode> decoded;
  require_hresult(
      decoder->GetFrame(0, decoded.GetAddressOf()),
      "automation_fixture_frame_failed");
  ComPtr<IWICFormatConverter> converter;
  require_hresult(
      factory.CreateFormatConverter(converter.GetAddressOf()),
      "automation_fixture_converter_failed");
  require_hresult(
      converter->Initialize(
          decoded.Get(),
          GUID_WICPixelFormat24bppBGR,
          WICBitmapDitherTypeNone,
          nullptr,
          0.0,
          WICBitmapPaletteTypeCustom),
      "automation_fixture_conversion_failed");
  UINT width = 0U;
  UINT height = 0U;
  require_hresult(
      converter->GetSize(&width, &height),
      "automation_fixture_size_failed");
  const auto stride = static_cast<std::size_t>(width) * 3U;
  const auto bytes = stride * static_cast<std::size_t>(height);
  require(bytes <= (std::numeric_limits<UINT>::max)(),
      "automation_fixture_too_large");
  std::vector<std::uint8_t> pixels(bytes);
  require_hresult(
      converter->CopyPixels(
          nullptr,
          static_cast<UINT>(stride),
          static_cast<UINT>(bytes),
          pixels.data()),
      "automation_fixture_copy_failed");
  return {width, height, stride, std::move(pixels)};
}

[[nodiscard]] std::vector<std::uint8_t> decode_base64(
    const std::string_view text) {
  constexpr std::string_view alphabet =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::vector<std::uint8_t> result;
  std::uint32_t accumulator = 0U;
  int bits = 0;
  for (const unsigned char character : text) {
    if (character == '=') {
      break;
    }
    if (std::isspace(character) != 0) {
      continue;
    }
    const auto position = alphabet.find(static_cast<char>(character));
    require(position != std::string_view::npos,
        "bubble_fixture_base64_invalid");
    accumulator = (accumulator << 6U) |
        static_cast<std::uint32_t>(position);
    bits += 6;
    if (bits >= 8) {
      bits -= 8;
      result.push_back(static_cast<std::uint8_t>(
          (accumulator >> bits) & 0xFFU));
    }
  }
  require(!result.empty(), "bubble_fixture_base64_empty");
  return result;
}

[[nodiscard]] bgr24_image load_bgr24_bytes(
    IWICImagingFactory& factory,
    const std::span<const std::uint8_t> bytes) {
  require(!bytes.empty(), "bubble_fixture_empty");
  HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, bytes.size());
  require(memory != nullptr, "bubble_fixture_allocation_failed");
  void* destination = GlobalLock(memory);
  if (destination == nullptr) {
    GlobalFree(memory);
    require(false, "bubble_fixture_lock_failed");
  }
  std::memcpy(destination, bytes.data(), bytes.size());
  GlobalUnlock(memory);
  ComPtr<IStream> stream;
  const HRESULT stream_result = CreateStreamOnHGlobal(
      memory, TRUE, stream.GetAddressOf());
  if (FAILED(stream_result)) {
    GlobalFree(memory);
    require_hresult(stream_result, "bubble_fixture_stream_failed");
  }
  ComPtr<IWICBitmapDecoder> decoder;
  require_hresult(
      factory.CreateDecoderFromStream(
          stream.Get(), nullptr, WICDecodeMetadataCacheOnLoad,
          decoder.GetAddressOf()),
      "bubble_fixture_decode_failed");
  ComPtr<IWICBitmapFrameDecode> decoded;
  require_hresult(
      decoder->GetFrame(0, decoded.GetAddressOf()),
      "bubble_fixture_frame_failed");
  ComPtr<IWICFormatConverter> converter;
  require_hresult(
      factory.CreateFormatConverter(converter.GetAddressOf()),
      "bubble_fixture_converter_failed");
  require_hresult(
      converter->Initialize(
          decoded.Get(), GUID_WICPixelFormat24bppBGR,
          WICBitmapDitherTypeNone, nullptr, 0.0,
          WICBitmapPaletteTypeCustom),
      "bubble_fixture_conversion_failed");
  UINT width = 0U;
  UINT height = 0U;
  require_hresult(converter->GetSize(&width, &height),
      "bubble_fixture_size_failed");
  const std::size_t stride = static_cast<std::size_t>(width) * 3U;
  std::vector<std::uint8_t> pixels(stride * height);
  require_hresult(
      converter->CopyPixels(
          nullptr, static_cast<UINT>(stride),
          static_cast<UINT>(pixels.size()), pixels.data()),
      "bubble_fixture_copy_failed");
  return {width, height, stride, std::move(pixels)};
}

[[nodiscard]] sonar::platform::windows::window_client_snapshot target() {
  return {
      .window = 0x1234U,
      .process = {
          .process_id = 77U,
          .creation_time_filetime_100ns = 99U,
      },
      .thread_id = 3U,
      .screen_left = -50,
      .screen_top = 20,
      .width = 1920U,
      .height = 1080U,
      .dpi = 96U,
      .visible = true,
      .minimized = false,
  };
}

[[nodiscard]] platform::client_frame frame_from(
    bgr24_image image,
    const std::uint64_t sequence = 1U,
    const std::uint64_t captured_at = 1'000U) {
  auto frame_target = target();
  frame_target.width = image.width;
  frame_target.height = image.height;
  return {
      .width = image.width,
      .height = image.height,
      .stride_bytes = image.stride,
      .sequence = sequence,
      .captured_at_steady_ns = captured_at,
      .target = frame_target,
      .bgr24 = std::move(image.pixels),
  };
}

void exact_legacy_bubble_templates_are_fallback_cues(
    IWICImagingFactory& factory) {
  const std::filesystem::path manifest(SONAR_FISHING_BUBBLE_FIXTURE);
  std::ifstream input(manifest);
  require(static_cast<bool>(input), "bubble_fixture_manifest_missing");
  std::string line;
  require(static_cast<bool>(std::getline(input, line)) &&
          line == "profile\tfile\tpng_sha256\twidth\theight",
      "bubble_fixture_manifest_header_changed");
  std::size_t cases = 0U;
  while (std::getline(input, line)) {
    if (line.empty()) {
      continue;
    }
    const auto fields = split_tabs(line);
    require(fields.size() == 5U && fields[2].size() == 64U,
        "bubble_fixture_manifest_row_invalid");
    std::ifstream encoded(manifest.parent_path() / fields[1]);
    require(static_cast<bool>(encoded), "bubble_fixture_payload_missing");
    const std::string base64{
        std::istreambuf_iterator<char>(encoded),
        std::istreambuf_iterator<char>()};
    auto templ = load_bgr24_bytes(factory, decode_base64(base64));
    require(templ.width == static_cast<std::uint32_t>(std::stoul(fields[3])) &&
            templ.height == static_cast<std::uint32_t>(std::stoul(fields[4])),
        "bubble_fixture_geometry_changed");

    const bool two_k = fields[0] == "2k";
    const std::uint32_t width = two_k ? 2560U : 1920U;
    const std::uint32_t height = two_k ? 1440U : 1080U;
    bgr24_image image{
        .width = width,
        .height = height,
        .stride = static_cast<std::size_t>(width) * 3U,
        .pixels = std::vector<std::uint8_t>(
            static_cast<std::size_t>(width) * height * 3U, 39U),
    };
    const std::uint32_t left = two_k ? 1820U : 1365U;
    const std::uint32_t top = two_k ? 1150U : 865U;
    for (std::uint32_t y = 0U; y < templ.height; ++y) {
      const auto source = static_cast<std::size_t>(y) * templ.stride;
      const auto target = static_cast<std::size_t>(top + y) * image.stride +
          static_cast<std::size_t>(left) * 3U;
      std::copy_n(
          templ.pixels.begin() + static_cast<std::ptrdiff_t>(source),
          static_cast<std::size_t>(templ.width) * 3U,
          image.pixels.begin() + static_cast<std::ptrdiff_t>(target));
    }
    const auto detected = adapters::detect_frame_semantics(
        frame_from(std::move(image)));
    require(detected.hook == episode::hook_cue::bubbles &&
            detected.hook_confidence >= 0.99,
        "legacy_bubble_fallback_not_detected");
    ++cases;
  }
  require(cases == 2U, "bubble_fixture_case_count_changed");

  bgr24_image blank{
      .width = 1920U,
      .height = 1080U,
      .stride = 1920U * 3U,
      .pixels = std::vector<std::uint8_t>(1920U * 1080U * 3U, 39U),
  };
  require(adapters::detect_frame_semantics(frame_from(std::move(blank))).hook ==
          episode::hook_cue::none,
      "blank_frame_triggered_bubble_fallback");
}

void screenshot_semantics_are_normalized_and_frozen(
    IWICImagingFactory& factory,
    const std::vector<fixture_case>& fixtures) {
  for (const auto& fixture : fixtures) {
    require(std::filesystem::file_size(fixture.image) == fixture.bytes,
        "automation_fixture_bytes_changed");
    auto image = load_bgr24(factory, fixture.image);
    require(image.width == fixture.width && image.height == fixture.height,
        "automation_fixture_geometry_changed");
    const auto detected = adapters::detect_frame_semantics(frame_from(
        std::move(image)));
    std::cout << "SEMANTIC " << fixture.image.filename().string()
              << " cast=" << detected.cast_ready
              << " cast_conf=" << detected.cast_confidence
              << " hook=" << static_cast<int>(detected.hook)
              << " hook_conf=" << detected.hook_confidence
              << " catch=" << detected.catch_visible << '\n';
    require(detected.cast_ready == fixture.cast_ready,
        "automation_cast_semantics_changed");
    require(detected.hook == fixture.hook,
        "automation_hook_semantics_changed");
    require(detected.catch_visible == fixture.catch_visible,
        "automation_catch_semantics_changed");
    require((detected.cast_confidence > 0.0) == detected.cast_ready,
        "automation_cast_confidence_ambiguous");
    require((detected.hook_confidence > 0.0) ==
            (detected.hook != episode::hook_cue::none),
        "automation_hook_confidence_ambiguous");
  }
}

class one_frame_capture final : public platform::client_capture_source {
 public:
  explicit one_frame_capture(platform::client_frame frame)
      : frame_(std::move(frame)) {}

  [[nodiscard]] platform::capture_result capture() override {
    if (!frame_.has_value()) {
      return platform::capture_result::unavailable("fixture_exhausted");
    }
    auto frame = std::move(*frame_);
    frame_.reset();
    return platform::capture_result::captured(std::move(frame));
  }

 private:
  std::optional<platform::client_frame> frame_;
};

class recording_memory final : public adapters::fishing_memory_source {
 public:
  [[nodiscard]] adapters::memory_snapshot_result capture(
      const std::uint64_t,
      const std::uint64_t,
      const sonar::platform::windows::process_generation&,
      const bool reeling_stage_visible) noexcept override {
    ++calls;
    reeling_requests.push_back(reeling_stage_visible);
    return {.reason = "fixture_memory_not_expected"};
  }

  std::size_t calls{};
  std::vector<bool> reeling_requests;
};

struct scripted_retry_state final {
  std::size_t resolve_calls{};
  std::size_t capture_calls{};
  std::size_t prepare_calls{};
  std::size_t commit_calls{};
  std::size_t reset_calls{};
  std::size_t observer_session_reset_calls{};
  std::size_t failures_remaining{};
  bool terminal_transition_pending{true};
  bool requested_only_reeling{true};
};

class scripted_retry_resolver final {
 public:
  explicit scripted_retry_resolver(scripted_retry_state& state) noexcept
      : state_(state) {}

  [[nodiscard]] sonar::fishing::memory_observation::resolved_memory_capture
  resolve_reeling(
      const std::uint64_t sequence,
      const std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept {
    ++state_.resolve_calls;
    return {
        .profile = sonar::fishing::memory_observation::memory_observation_profile{
            .profile_id = "retry-adapter-fixture-v1",
            .profile_revision = 1U,
        },
        .plan = sonar::fishing::memory_observation::capture_plan{
            .sequence = sequence,
            .captured_at_steady_ns = captured_at_steady_ns,
            .game_process_id = game_generation.process_id,
            .expected_game_generation = game_generation,
        },
        .registry_sha256 = std::string(
            sonar::fishing::memory_observation::
                embedded_build_profile_registry_sha256),
    };
  }

  void commit_capture(
      const sonar::fishing::memory_observation::coherent_memory_snapshot&
          snapshot) noexcept {
    ++state_.commit_calls;
    if (snapshot.reeling.has_value() && !snapshot.reeling->active) {
      state_.terminal_transition_pending = false;
    }
  }

  void prepare_capture_retry() noexcept {
    ++state_.prepare_calls;
  }

  [[nodiscard]] bool terminal_transition_pending() const noexcept {
    return state_.terminal_transition_pending;
  }

  void reset() noexcept {
    ++state_.reset_calls;
    state_.terminal_transition_pending = false;
  }

 private:
  scripted_retry_state& state_;
};

class scripted_retry_observer final {
 public:
  explicit scripted_retry_observer(scripted_retry_state& state) noexcept
      : state_(state) {}

  [[nodiscard]] sonar::fishing::memory_observation::capture_result capture(
      const sonar::fishing::memory_observation::memory_observation_profile&
          profile,
      const sonar::fishing::memory_observation::capture_plan& plan) noexcept {
    ++state_.capture_calls;
    if (state_.failures_remaining != 0U) {
      --state_.failures_remaining;
      return {
          .failure =
              sonar::fishing::memory_observation::capture_failure::read_failed,
          .reason = "retry_adapter_fixture_read_failed",
      };
    }
    return {
        .snapshot =
            sonar::fishing::memory_observation::coherent_memory_snapshot{
                .sequence = plan.sequence,
                .captured_at_steady_ns = plan.captured_at_steady_ns,
                .profile_id = profile.profile_id,
                .profile_revision = profile.profile_revision,
                .game_generation = plan.expected_game_generation,
                .reeling =
                    sonar::fishing::memory_observation::reeling_evidence{
                        .active = false,
                        .fish_model_confirmed = true,
                    },
            },
    };
  }

  void reset_sessions() noexcept {
    ++state_.observer_session_reset_calls;
  }

 private:
  scripted_retry_state& state_;
};

void terminal_memory_transition_is_bounded_and_committed_once() {
  const sonar::platform::windows::process_generation generation{
      .process_id = 101U,
      .creation_time_filetime_100ns = 202U,
  };

  scripted_retry_state recovered{.failures_remaining = 1U};
  scripted_retry_resolver recovered_resolver(recovered);
  scripted_retry_observer recovered_observer(recovered);
  const auto snapshot =
      sonar::fishing::automation_adapters::detail::
          capture_reeling_with_bounded_retry(
              recovered_resolver,
              recovered_observer,
              71U,
              9'000U,
              generation);
  require(snapshot.snapshot.has_value() &&
          snapshot.snapshot->reeling.has_value() &&
          !snapshot.snapshot->reeling->active,
      "retry_adapter_inactive_snapshot_missing");
  require(recovered.resolve_calls == 2U && recovered.capture_calls == 2U &&
          recovered.prepare_calls == 1U && recovered.commit_calls == 1U &&
          recovered.reset_calls == 0U &&
          recovered.observer_session_reset_calls == 1U &&
          !recovered.terminal_transition_pending &&
          recovered.requested_only_reeling,
      "retry_adapter_terminal_transition_not_committed_once");

  scripted_retry_state exhausted{.failures_remaining = 2U};
  scripted_retry_resolver exhausted_resolver(exhausted);
  scripted_retry_observer exhausted_observer(exhausted);
  const auto unavailable =
      sonar::fishing::automation_adapters::detail::
          capture_reeling_with_bounded_retry(
              exhausted_resolver,
              exhausted_observer,
              72U,
              9'100U,
              generation);
  require(!unavailable.snapshot.has_value() &&
          unavailable.reason == "retry_adapter_fixture_read_failed" &&
          exhausted.resolve_calls == 2U && exhausted.capture_calls == 2U &&
          exhausted.prepare_calls == 1U && exhausted.commit_calls == 0U &&
          exhausted.reset_calls == 1U &&
          exhausted.observer_session_reset_calls == 2U &&
          !exhausted.terminal_transition_pending &&
          exhausted.requested_only_reeling,
      "retry_adapter_exhaustion_left_pending_transition");
}

class recording_gate final : public adapters::immediate_action_gate {
 public:
  [[nodiscard]] adapters::action_gate_result revalidate(
      const adapters::action_claim& claim) noexcept override {
    claims.push_back(claim);
    return accepted
        ? adapters::action_gate_result{true, {}}
        : adapters::action_gate_result{false, reason};
  }

  bool accepted{true};
  std::string reason{"fixture_gate_rejected"};
  std::vector<adapters::action_claim> claims;
};

class recording_sink final : public platform::platform_mutation_sink {
 public:
  [[nodiscard]] platform::mutation_result apply(
      const platform::mutation_intent& intent) override {
    intents.push_back(intent);
    return accepted
        ? platform::mutation_result::accepted()
        : platform::mutation_result::rejected("fixture_sink_rejected");
  }

  bool accepted{true};
  std::vector<platform::mutation_intent> intents;
};

[[nodiscard]] episode::fishing_episode_request request() {
  return {
      .automation_enabled = true,
      .accepted_settings_revision = 4U,
      .expected_entitlement_revision = 5U,
      .expected_lifecycle_revision = 6U,
      .episode_identity = 7U,
  };
}

[[nodiscard]] episode::fishing_mutation_intent cast_intent() {
  return {
      .kind = episode::fishing_mutation_kind::tap_cast_space,
      .expected_observation_sequence = 17U,
      .expected_settings_revision = 4U,
      .expected_entitlement_revision = 5U,
      .expected_lifecycle_revision = 6U,
      .packet_count = 2U,
  };
}

void coherent_frame_feeds_one_observation(
    IWICImagingFactory& factory,
    const fixture_case& casting) {
  one_frame_capture capture(frame_from(
      load_bgr24(factory, casting.image), 17U, 9'000U));
  sonar::fishing::stage_detection::majestic_fishing_stage_detector detector;
  recording_memory memory;
  adapters::mutable_runtime_policy_source policy;
  adapters::frame_fishing_observer observer(
      capture, detector, memory, policy);
  const auto observed = observer.observe({});
  require(observed.error.empty(), "frame_observer_failed");
  require(observed.sequence == 17U &&
          observed.captured_at_steady_ns == 9'000U,
      "frame_observation_identity_changed");
  require(observed.stage.has_value() &&
          observed.stage->stage ==
              sonar::fishing::stage_detection::observed_fishing_stage::casting,
      "frame_stage_not_connected");
  require(observed.cast_ready && observed.hook == episode::hook_cue::none,
      "frame_semantics_not_connected");
  require(memory.calls == 0U, "memory_read_outside_reeling_stage");
  require(policy.snapshot().latest_observation_sequence == 17U,
      "policy_observation_sequence_not_published");
}

void one_lease_and_immediate_gate_own_mutation() {
  platform::automation_lease_coordinator leases;
  recording_gate gate;
  recording_sink sink;
  adapters::guarded_fishing_mutation_port port(leases, gate, sink);
  std::string reason;
  auto session = port.acquire(request(), {}, reason);
  require(session != nullptr && reason.empty(),
      "fishing_mutation_lease_not_acquired");
  std::string second_reason;
  require(port.acquire(request(), {}, second_reason) == nullptr &&
          second_reason == "fishing_input_lease_busy",
      "fishing_mutation_lease_not_exclusive");

  auto malformed = cast_intent();
  malformed.packet_count = 1U;
  require(session->apply(malformed, {}).reason ==
          "fishing_mutation_packet_shape_invalid",
      "fishing_packet_shape_not_rejected");
  require(gate.claims.empty() && sink.intents.empty(),
      "malformed_packet_reached_final_gate");

  const auto applied = session->apply(cast_intent(), {});
  require(applied.applied && gate.claims.size() == 1U &&
          sink.intents.size() == 1U,
      "fishing_cast_mutation_not_applied");
  require(gate.claims[0].expected_observation_sequence == 17U &&
          gate.claims[0].packet_count == 2U &&
          gate.claims[0].foreground_required,
      "fishing_final_gate_claim_changed");
  require(sink.intents[0].kind == platform::mutation_kind::press_key &&
          sink.intents[0].primary == "space" &&
          sink.intents[0].packet_count == 2U,
      "fishing_cast_packet_projection_changed");

  gate.accepted = false;
  const auto blocked = session->apply(cast_intent(), {});
  require(!blocked.applied && blocked.reason == gate.reason &&
          sink.intents.size() == 1U,
      "rejected_final_gate_reached_platform_sink");

  gate.accepted = true;
  const auto pulse = session->apply({
      .kind = episode::fishing_mutation_kind::pulse_reeling_key,
      .expected_observation_sequence = 17U,
      .expected_settings_revision = 4U,
      .expected_entitlement_revision = 5U,
      .expected_lifecycle_revision = 6U,
      .desired_reeling_key = sonar::fishing::reeling_control::HeldKey::a,
      .packet_count = 2U,
  }, {});
  require(pulse.applied && sink.intents.size() == 2U &&
          sink.intents.back().kind == platform::mutation_kind::press_key &&
          sink.intents.back().primary == "a" &&
          sink.intents.back().packet_count == 2U,
      "fishing_reeling_pulse_not_atomic_pair");
  require(std::ranges::none_of(
              sink.intents,
              [](const platform::mutation_intent& projected) {
                return projected.kind == platform::mutation_kind::key_down ||
                    projected.kind == platform::mutation_kind::key_up ||
                    projected.kind ==
                        platform::mutation_kind::switch_held_key;
              }),
      "fishing_reeling_projection_retained_held_key_state");

  const auto cleanup = session->cleanup_reeling_keys(17U);
  require(cleanup.applied && gate.claims.back().cleanup_only &&
          !gate.claims.back().foreground_required &&
          sink.intents.back().kind ==
              platform::mutation_kind::release_reeling_keys &&
          sink.intents.back().packet_count == 2U,
      "fishing_cleanup_contract_changed");

  session.reset();
  reason.clear();
  require(port.acquire(request(), {}, reason) != nullptr,
      "fishing_mutation_lease_not_released");
}

void policy_snapshot_is_coherent_and_stop_revokes_actions() {
  adapters::mutable_runtime_policy_source policy;
  policy.publish({
      .entitlement_valid = true,
      .settings_current = true,
      .lifecycle_allows_input = true,
      .settings_revision = 4U,
      .entitlement_revision = 5U,
      .entitlement_expires_unix_seconds = 100U,
      .lifecycle_revision = 6U,
      .latest_observation_sequence = 16U,
  });
  policy.observe(17U);
  auto snapshot = policy.snapshot();
  require(snapshot.entitlement_valid && snapshot.settings_current &&
          snapshot.lifecycle_allows_input &&
          snapshot.entitlement_valid_at(99) &&
          !snapshot.entitlement_valid_at(100) &&
          snapshot.latest_observation_sequence == 17U,
      "runtime_policy_snapshot_changed");
  require(!policy.refresh_entitlement_expiry(6U, 200) &&
          policy.refresh_entitlement_expiry(5U, 200) &&
          policy.snapshot().entitlement_valid_at(199),
      "runtime_policy_entitlement_refresh_changed");
  policy.stop();
  snapshot = policy.snapshot();
  require(!snapshot.lifecycle_allows_input &&
          snapshot.entitlement_valid && snapshot.settings_current,
      "runtime_policy_stop_scope_changed");
}

}  // namespace

int main(const int argc, const char* const argv[]) {
  try {
    com_apartment apartment;
    ComPtr<IWICImagingFactory> factory;
    require_hresult(
        CoCreateInstance(
            CLSID_WICImagingFactory,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(factory.GetAddressOf())),
        "automation_fixture_factory_failed");
    const auto fixtures = load_manifest();
    screenshot_semantics_are_normalized_and_frozen(*factory.Get(), fixtures);
    exact_legacy_bubble_templates_are_fallback_cues(*factory.Get());
    coherent_frame_feeds_one_observation(*factory.Get(), fixtures[0]);
    terminal_memory_transition_is_bounded_and_committed_once();
    one_lease_and_immediate_gate_own_mutation();
    policy_snapshot_is_coherent_and_stop_revokes_actions();
    if (argc == 2) {
      for (const auto& entry : std::filesystem::directory_iterator(argv[1])) {
        if (!entry.is_regular_file()) {
          continue;
        }
        const auto extension = entry.path().extension().string();
        if (extension != ".jpg" && extension != ".jpeg" &&
            extension != ".png") {
          continue;
        }
        try {
          const auto detected = adapters::detect_frame_semantics(
              frame_from(load_bgr24(*factory.Get(), entry.path())));
          if (detected.hook == episode::hook_cue::bubbles) {
            std::cout << "BUBBLES " << entry.path().filename().string()
                      << " confidence=" << detected.hook_confidence << '\n';
          }
        } catch (const std::exception&) {
        }
      }
    }
    std::cout << "PASS Fishing automation adapters offline fixtures 6/6\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
