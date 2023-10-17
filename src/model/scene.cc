#include "include/scene.h"

namespace s21 {

NormalizationParameters Scene::GetNormalizationParams() {
  return normalization_params_;
}

void Scene::SetNormalizationParams(NormalizationParameters params) {
  normalization_params_ = params;
}

} // namespace s21
