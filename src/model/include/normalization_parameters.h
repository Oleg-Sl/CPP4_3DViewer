#ifndef _3DVIEWER_MODEL_NORMALIZATION_PARAMETERS_H_
#define _3DVIEWER_MODEL_NORMALIZATION_PARAMETERS_H_

#include <limits>

namespace s21 {

struct NormalizationParameters {
  float min = std::numeric_limits<float>::max();
  float max = std::numeric_limits<float>::min();
  float dx_step;
  float dy_step;
};

} // namespace s21

#endif // _3DVIEWER_MODEL_NORMALIZATION_PARAMETERS_H_
