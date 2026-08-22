#pragma once

#include "stage_image.h"

namespace sonar::fishing::stage_detection::detail {

enum class stage_resolution_profile {
  full_hd,
  two_k,
};

struct stage_template_catalog final {
  gray_image ad;
  gray_image start;
  gray_image cast;
  gray_image hook;
  gray_image wait;
};

[[nodiscard]] const stage_template_catalog& stage_templates(
    stage_resolution_profile profile);

}  // namespace sonar::fishing::stage_detection::detail
