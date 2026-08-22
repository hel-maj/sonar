#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>
#include <Psapi.h>
#include <wincodec.h>
#include <wrl/client.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

using Microsoft::WRL::ComPtr;
using sonar::fishing::stage_detection::bgr24_frame_view;
using sonar::fishing::stage_detection::majestic_fishing_stage_detector;
using sonar::fishing::stage_detection::observed_fishing_stage;
using sonar::fishing::stage_detection::stage_key;

struct bgr24_image final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t stride{};
  std::vector<std::uint8_t> pixels;
};

struct fixture_case final {
  std::filesystem::path image;
  observed_fishing_stage expected{observed_fishing_stage::none};
  std::string oracle_trigger;
  double oracle_confidence{};
};

void require(const bool condition, const std::string_view message) {
  if (!condition) {
    throw std::runtime_error(std::string(message));
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
  std::size_t start = 0;
  while (true) {
    const auto separator = line.find('\t', start);
    if (separator == std::string::npos) {
      fields.push_back(line.substr(start));
      return fields;
    }
    fields.push_back(line.substr(start, separator - start));
    start = separator + 1;
  }
}

[[nodiscard]] observed_fishing_stage parse_stage(const std::string_view value) {
  if (value == "none") {
    return observed_fishing_stage::none;
  }
  if (value == "tackle_selection") {
    return observed_fishing_stage::tackle_selection;
  }
  if (value == "casting") {
    return observed_fishing_stage::casting;
  }
  if (value == "waiting_for_bite") {
    return observed_fishing_stage::waiting_for_bite;
  }
  if (value == "reeling") {
    return observed_fishing_stage::reeling;
  }
  throw std::runtime_error("fishing_stage_manifest_stage_invalid");
}

[[nodiscard]] std::vector<fixture_case> load_manifest() {
  const std::filesystem::path manifest =
      SONAR_FISHING_STAGE_SCREENSHOT_MANIFEST;
  std::ifstream stream(manifest);
  require(stream.good(), "fishing_stage_manifest_missing");
  std::string line;
  require(static_cast<bool>(std::getline(stream, line)),
          "fishing_stage_manifest_empty");
  require(
      line == "file\tsha256\tbytes\twidth\theight\texpected_stage\toracle_trigger\toracle_confidence",
      "fishing_stage_manifest_header_changed");
  std::vector<fixture_case> result;
  while (std::getline(stream, line)) {
    if (line.empty()) {
      continue;
    }
    const auto fields = split_tabs(line);
    require(fields.size() == 8, "fishing_stage_manifest_row_invalid");
    result.push_back({
        .image = manifest.parent_path() / fields[0],
        .expected = parse_stage(fields[5]),
        .oracle_trigger = fields[6],
        .oracle_confidence = std::stod(fields[7]),
    });
  }
  require(result.size() == 30, "fishing_stage_manifest_count_changed");
  return result;
}

class com_apartment final {
 public:
  com_apartment() {
    require_hresult(
        CoInitializeEx(nullptr, COINIT_MULTITHREADED),
        "fishing_stage_com_initialize_failed");
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
      "fishing_stage_fixture_open_failed");
  ComPtr<IWICBitmapFrameDecode> decoded;
  require_hresult(
      decoder->GetFrame(0, decoded.GetAddressOf()),
      "fishing_stage_fixture_frame_failed");
  ComPtr<IWICFormatConverter> converter;
  require_hresult(
      factory.CreateFormatConverter(converter.GetAddressOf()),
      "fishing_stage_fixture_converter_failed");
  require_hresult(
      converter->Initialize(
          decoded.Get(),
          GUID_WICPixelFormat24bppBGR,
          WICBitmapDitherTypeNone,
          nullptr,
          0.0,
          WICBitmapPaletteTypeCustom),
      "fishing_stage_fixture_conversion_failed");
  UINT width = 0;
  UINT height = 0;
  require_hresult(
      converter->GetSize(&width, &height),
      "fishing_stage_fixture_size_failed");
  const auto stride = static_cast<std::size_t>(width) * 3;
  const auto bytes = stride * height;
  require(bytes <= std::numeric_limits<UINT>::max(),
          "fishing_stage_fixture_too_large");
  std::vector<std::uint8_t> pixels(bytes);
  require_hresult(
      converter->CopyPixels(
          nullptr,
          static_cast<UINT>(stride),
          static_cast<UINT>(bytes),
          pixels.data()),
      "fishing_stage_fixture_copy_failed");
  return {
      .width = width,
      .height = height,
      .stride = stride,
      .pixels = std::move(pixels),
  };
}

[[nodiscard]] bgr24_frame_view view(const bgr24_image& image) noexcept {
  return {
      .width = image.width,
      .height = image.height,
      .stride_bytes = image.stride,
      .pixels = image.pixels,
  };
}

[[nodiscard]] std::uint64_t filetime_ticks(const FILETIME value) noexcept {
  ULARGE_INTEGER combined{};
  combined.LowPart = value.dwLowDateTime;
  combined.HighPart = value.dwHighDateTime;
  return combined.QuadPart;
}

}  // namespace

int main() {
  try {
    const majestic_fishing_stage_detector detector;
    const auto invalid = detector.detect({});
    require(!invalid.observation.has_value() &&
            invalid.error == "fishing_stage_frame_invalid",
            "fishing_stage_invalid_frame_not_fail_closed");

    com_apartment apartment;
    ComPtr<IWICImagingFactory> factory;
    require_hresult(
        CoCreateInstance(
            CLSID_WICImagingFactory,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(factory.GetAddressOf())),
        "fishing_stage_fixture_factory_failed");

    const auto fixtures = load_manifest();
    std::vector<double> elapsed_milliseconds;
    double maximum_oracle_delta = 0.0;
    for (const auto& fixture : fixtures) {
      const auto image = load_bgr24(*factory.Get(), fixture.image);
      const auto started = std::chrono::steady_clock::now();
      const auto detected = detector.detect(view(image));
      elapsed_milliseconds.push_back(std::chrono::duration<double, std::milli>(
          std::chrono::steady_clock::now() - started).count());
      const auto context = fixture.image.filename().string();
      require(detected.error.empty(), context + ":detector_error");
      if (fixture.expected == observed_fishing_stage::none) {
        require(!detected.observation.has_value(),
                context + ":false_positive");
        continue;
      }
      require(detected.observation.has_value(), context + ":stage_missing");
      require(detected.observation->stage == fixture.expected,
              context + ":stage_changed");
      require(detected.observation->trigger_id == fixture.oracle_trigger,
              context + ":precedence_changed");
      const auto confidence_delta = std::abs(
          detected.observation->confidence - fixture.oracle_confidence);
      maximum_oracle_delta = std::max(maximum_oracle_delta, confidence_delta);
      require(confidence_delta <= 0.025,
              context + ":confidence_drifted");
      const auto& bounds = detected.observation->bounds;
      require(bounds.x >= 0.0 && bounds.y >= 0.0 &&
              bounds.width > 0.0 && bounds.height > 0.0 &&
              bounds.x + bounds.width <= 1.0 &&
              bounds.y + bounds.height <= 1.0,
              context + ":normalized_bounds_invalid");
    }

    std::ranges::sort(elapsed_milliseconds);
    const auto percentile = [&](const double value) {
      const auto index = static_cast<std::size_t>(std::ceil(
          value * static_cast<double>(elapsed_milliseconds.size()))) - 1;
      return elapsed_milliseconds[std::min(
          index, elapsed_milliseconds.size() - 1)];
    };
    PROCESS_MEMORY_COUNTERS memory{};
    memory.cb = sizeof(memory);
    require(
        GetProcessMemoryInfo(
            GetCurrentProcess(), &memory, sizeof(memory)) != FALSE,
        "fishing_stage_process_memory_unavailable");
    FILETIME created{};
    FILETIME exited{};
    FILETIME kernel{};
    FILETIME user{};
    require(
        GetProcessTimes(
            GetCurrentProcess(), &created, &exited, &kernel, &user) != FALSE,
        "fishing_stage_process_time_unavailable");
    const auto cpu_milliseconds = static_cast<double>(
        filetime_ticks(kernel) + filetime_ticks(user)) / 10'000.0;
    std::cout << "METRIC fishing_stage_detector frames="
              << elapsed_milliseconds.size()
              << " p50_ms=" << percentile(0.50)
              << " p95_ms=" << percentile(0.95)
              << " max_ms=" << elapsed_milliseconds.back()
              << " max_oracle_confidence_delta=" << maximum_oracle_delta
              << " process_cpu_ms=" << cpu_milliseconds
              << " peak_working_set_bytes=" << memory.PeakWorkingSetSize
              << '\n';
    std::cout << "PASS Fishing stage detector corpus "
              << fixtures.size() << '/' << fixtures.size() << '\n';
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
