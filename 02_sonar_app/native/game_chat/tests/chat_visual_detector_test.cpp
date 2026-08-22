#include "sonar/fishing/game_chat/chat_observation.h"

#include <Windows.h>
#include <Psapi.h>
#include <wincodec.h>
#include <wrl/client.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

using Microsoft::WRL::ComPtr;
using sonar::fishing::game_chat::chat_frame;
using sonar::fishing::game_chat::majestic_chat_frame_detector;
using sonar::fishing::game_chat::pixel_rect;

struct fixture_case final {
  std::filesystem::path image;
  bool active{};
  std::string selected_tab;
  std::size_t minimum_tabs{};
  std::optional<pixel_rect> input;
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

[[nodiscard]] std::vector<std::string> split_tabs(
    const std::string& line) {
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

[[nodiscard]] std::vector<fixture_case> load_manifest() {
  const std::filesystem::path manifest =
      SONAR_FISHING_CHAT_SCREENSHOT_MANIFEST;
  std::ifstream stream(manifest);
  require(stream.good(), "chat_screenshot_manifest_missing");
  std::string line;
  require(static_cast<bool>(std::getline(stream, line)),
          "chat_screenshot_manifest_empty");
  require(line ==
          "file\tsha256\tbytes\twidth\theight\tactive\tselected_tab\tminimum_tabs\tinput_x\tinput_y\tinput_width\tinput_height",
          "chat_screenshot_manifest_header_changed");
  std::vector<fixture_case> result;
  while (std::getline(stream, line)) {
    if (line.empty()) {
      continue;
    }
    const auto fields = split_tabs(line);
    require(fields.size() == 12, "chat_screenshot_manifest_row_invalid");
    fixture_case item{
        .image = manifest.parent_path() / fields[0],
        .active = fields[5] == "true",
        .selected_tab = fields[6],
        .minimum_tabs = static_cast<std::size_t>(std::stoull(fields[7])),
    };
    if (fields[8] != "-") {
      item.input = pixel_rect{
          .x = static_cast<std::uint32_t>(std::stoul(fields[8])),
          .y = static_cast<std::uint32_t>(std::stoul(fields[9])),
          .width = static_cast<std::uint32_t>(std::stoul(fields[10])),
          .height = static_cast<std::uint32_t>(std::stoul(fields[11])),
      };
    }
    result.push_back(std::move(item));
  }
  require(result.size() == 12, "chat_screenshot_manifest_count_changed");
  return result;
}

class com_apartment final {
 public:
  com_apartment() {
    const auto result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    require_hresult(result, "chat_fixture_com_initialize_failed");
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

[[nodiscard]] chat_frame load_bgr24(
    IWICImagingFactory& factory,
    const std::filesystem::path& path,
    const std::uint64_t sequence) {
  ComPtr<IWICBitmapDecoder> decoder;
  require_hresult(
      factory.CreateDecoderFromFilename(
          path.c_str(),
          nullptr,
          GENERIC_READ,
          WICDecodeMetadataCacheOnLoad,
          decoder.GetAddressOf()),
      "chat_fixture_decode_open_failed");
  ComPtr<IWICBitmapFrameDecode> decoded;
  require_hresult(
      decoder->GetFrame(0, decoded.GetAddressOf()),
      "chat_fixture_decode_frame_failed");
  ComPtr<IWICFormatConverter> converted;
  require_hresult(
      factory.CreateFormatConverter(converted.GetAddressOf()),
      "chat_fixture_converter_create_failed");
  require_hresult(
      converted->Initialize(
          decoded.Get(),
          GUID_WICPixelFormat24bppBGR,
          WICBitmapDitherTypeNone,
          nullptr,
          0.0,
          WICBitmapPaletteTypeCustom),
      "chat_fixture_convert_failed");
  UINT width = 0;
  UINT height = 0;
  require_hresult(
      converted->GetSize(&width, &height),
      "chat_fixture_size_failed");
  const auto stride = static_cast<std::size_t>(width) * 3;
  const auto byte_count = stride * height;
  require(byte_count <= std::numeric_limits<UINT>::max(),
          "chat_fixture_image_too_large");
  std::vector<std::uint8_t> pixels(byte_count);
  require_hresult(
      converted->CopyPixels(
          nullptr,
          static_cast<UINT>(stride),
          static_cast<UINT>(byte_count),
          pixels.data()),
      "chat_fixture_copy_failed");
  return {
      .width = width,
      .height = height,
      .stride_bytes = stride,
      .sequence = sequence,
      .bgr24 = std::move(pixels),
  };
}

[[nodiscard]] bool same_rect(
    const pixel_rect& left,
    const pixel_rect& right) noexcept {
  return left.x == right.x && left.y == right.y &&
      left.width == right.width && left.height == right.height;
}

}  // namespace

int main() {
  try {
    com_apartment apartment;
    ComPtr<IWICImagingFactory> factory;
    require_hresult(
        CoCreateInstance(
            CLSID_WICImagingFactory,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(factory.GetAddressOf())),
        "chat_fixture_factory_failed");
    const auto fixtures = load_manifest();
    majestic_chat_frame_detector detector;
    std::vector<double> elapsed_milliseconds;
    std::uint64_t sequence = 1;
    for (const auto& fixture : fixtures) {
      const auto frame = load_bgr24(*factory.Get(), fixture.image, sequence++);
      const auto started = std::chrono::steady_clock::now();
      const auto detected = detector.detect(frame);
      elapsed_milliseconds.push_back(std::chrono::duration<double, std::milli>(
          std::chrono::steady_clock::now() - started).count());
      const auto context = fixture.image.filename().string();
      require(detected.error.empty(), context + ":detector_error");
      require(detected.active == fixture.active, context + ":active_changed");
      require(detected.selected_tab_id == fixture.selected_tab,
              context + ":selected_tab_changed");
      require(detected.tabs.size() >= fixture.minimum_tabs,
              context + ":tab_count_changed");
      require(detected.tabs[0].id == "0" && detected.tabs[0].name == "Все",
              context + ":all_tab_identity_changed");
      require(detected.tabs[1].id == "1" && detected.tabs[1].name == "Семья",
              context + ":family_tab_identity_changed");
      require(detected.input_bounds.has_value() == fixture.input.has_value(),
              context + ":input_presence_changed");
      if (fixture.input.has_value()) {
        require(same_rect(*detected.input_bounds, *fixture.input),
                context + ":input_bounds_changed");
      }
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
        "chat_detector_process_memory_unavailable");
    FILETIME created{};
    FILETIME exited{};
    FILETIME kernel{};
    FILETIME user{};
    require(
        GetProcessTimes(
            GetCurrentProcess(), &created, &exited, &kernel, &user) != FALSE,
        "chat_detector_process_time_unavailable");
    const auto filetime_ticks = [](const FILETIME value) {
      ULARGE_INTEGER combined{};
      combined.LowPart = value.dwLowDateTime;
      combined.HighPart = value.dwHighDateTime;
      return combined.QuadPart;
    };
    const auto cpu_milliseconds = static_cast<double>(
        filetime_ticks(kernel) + filetime_ticks(user)) / 10'000.0;
    std::cout << "METRIC game_chat_detector frames="
              << elapsed_milliseconds.size()
              << " p50_ms=" << percentile(0.50)
              << " p95_ms=" << percentile(0.95)
              << " max_ms=" << elapsed_milliseconds.back()
              << " process_cpu_ms=" << cpu_milliseconds
              << " peak_working_set_bytes=" << memory.PeakWorkingSetSize
              << '\n';
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
