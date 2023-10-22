#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include <ctime>
#include <vector>

#include "normalization_parameters.h"
#include "transform_matrix.h"

namespace s21 {

class Scene {
public:
  NormalizationParameters GetNormalizationParams();
  size_t GetCountVertices() const;
  size_t GetCountEdges() const;
  void SetNormalizationParams(NormalizationParameters &&params);
  void SetEdges(std::vector<int> &&edges);
  void TransformVertices(const TransformMatrix &matrix);
  void SetVertices(std::vector<float> &&vertices);
  const std::vector<float> &GetVertices();
  const std::vector<int> &GetEdges();

private:
  std::vector<float> vertices_;
  std::vector<int> edges_;
  NormalizationParameters normalization_params_;
};

} // namespace s21

#endif // _3DVIEWER_MODEL_SCENE_H_
