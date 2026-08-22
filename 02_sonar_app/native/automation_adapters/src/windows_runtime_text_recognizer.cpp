#include "sonar/fishing/automation_adapters/production_observation.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>

#include <winrt/Windows.Globalization.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <winrt/Windows.Media.Ocr.h>
#include <winrt/base.h>

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace sonar::fishing::automation_adapters {
namespace {

class windows_runtime_text_recognizer final : public runtime_text_recognizer {
 public:
  windows_runtime_text_recognizer() {
    winrt::init_apartment(winrt::apartment_type::multi_threaded);
    apartment_initialized_ = true;
    engine_ = winrt::Windows::Media::Ocr::OcrEngine::TryCreateFromLanguage(
        winrt::Windows::Globalization::Language(L"ru-RU"));
    if (!engine_) {
      engine_ = winrt::Windows::Media::Ocr::OcrEngine::
          TryCreateFromUserProfileLanguages();
    }
    if (!engine_) {
      throw winrt::hresult_error(E_FAIL);
    }
  }

  ~windows_runtime_text_recognizer() override {
    engine_ = nullptr;
    if (apartment_initialized_) {
      winrt::uninit_apartment();
    }
  }

  [[nodiscard]] recognized_text recognize(
      const runtime_platform::client_frame& frame,
      const stage_detection::normalized_rect& bounds) noexcept override {
    if (!frame.valid() || !valid(bounds) || !engine_) {
      return {.reason = "production_ocr_request_invalid"};
    }
    try {
      const auto left = static_cast<std::uint32_t>(std::clamp(
          std::llround(bounds.x * frame.width), 0LL,
          static_cast<long long>(frame.width - 1U)));
      const auto top = static_cast<std::uint32_t>(std::clamp(
          std::llround(bounds.y * frame.height), 0LL,
          static_cast<long long>(frame.height - 1U)));
      const auto right = static_cast<std::uint32_t>(std::clamp(
          std::llround((bounds.x + bounds.width) * frame.width),
          static_cast<long long>(left + 1U),
          static_cast<long long>(frame.width)));
      const auto bottom = static_cast<std::uint32_t>(std::clamp(
          std::llround((bounds.y + bounds.height) * frame.height),
          static_cast<long long>(top + 1U),
          static_cast<long long>(frame.height)));
      const auto width = right - left;
      const auto height = bottom - top;
      auto bitmap = winrt::Windows::Graphics::Imaging::SoftwareBitmap(
          winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8,
          static_cast<std::int32_t>(width),
          static_cast<std::int32_t>(height),
          winrt::Windows::Graphics::Imaging::BitmapAlphaMode::Ignore);
      auto buffer = bitmap.LockBuffer(
          winrt::Windows::Graphics::Imaging::BitmapBufferAccessMode::Write);
      const auto plane = buffer.GetPlaneDescription(0);
      auto reference = buffer.CreateReference();
      auto access = reference.as<winrt::impl::IMemoryBufferByteAccess>();
      BYTE* bytes = nullptr;
      UINT32 capacity = 0U;
      winrt::check_hresult(access->GetBuffer(&bytes, &capacity));
      if (bytes == nullptr || plane.StartIndex < 0 || plane.Stride < 0 ||
          static_cast<std::uint64_t>(plane.StartIndex) +
              static_cast<std::uint64_t>(plane.Stride) * height > capacity) {
        return {.reason = "production_ocr_buffer_invalid"};
      }
      for (std::uint32_t y = 0U; y < height; ++y) {
        const auto source = static_cast<std::size_t>(top + y) *
                frame.stride_bytes +
            static_cast<std::size_t>(left) * 3U;
        auto* destination = bytes + plane.StartIndex +
            static_cast<std::size_t>(y) * plane.Stride;
        for (std::uint32_t x = 0U; x < width; ++x) {
          destination[x * 4U] = frame.bgr24[source + x * 3U];
          destination[x * 4U + 1U] = frame.bgr24[source + x * 3U + 1U];
          destination[x * 4U + 2U] = frame.bgr24[source + x * 3U + 2U];
          destination[x * 4U + 3U] = 0xFFU;
        }
      }
      auto text = winrt::to_string(engine_.RecognizeAsync(bitmap).get().Text());
      while (!text.empty() &&
             std::isspace(static_cast<unsigned char>(text.front())) != 0) {
        text.erase(text.begin());
      }
      while (!text.empty() &&
             std::isspace(static_cast<unsigned char>(text.back())) != 0) {
        text.pop_back();
      }
      return {.text = std::move(text)};
    } catch (...) {
      return {.reason = "production_ocr_failed"};
    }
  }

 private:
  [[nodiscard]] static bool valid(
      const stage_detection::normalized_rect& value) noexcept {
    return std::isfinite(value.x) && std::isfinite(value.y) &&
        std::isfinite(value.width) && std::isfinite(value.height) &&
        value.x >= 0.0 && value.y >= 0.0 && value.width > 0.0 &&
        value.height > 0.0 && value.x + value.width <= 1.0 &&
        value.y + value.height <= 1.0;
  }

  bool apartment_initialized_{};
  winrt::Windows::Media::Ocr::OcrEngine engine_{nullptr};
};

}  // namespace

std::unique_ptr<runtime_text_recognizer>
make_windows_runtime_text_recognizer() noexcept {
  try {
    return std::make_unique<windows_runtime_text_recognizer>();
  } catch (...) {
    return nullptr;
  }
}

}  // namespace sonar::fishing::automation_adapters
