#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include <ctime>
#include <vector>

#include "figure.h"
#include "transform_matrix.h"

namespace s21 {

class Scene {
public:
  NormalizationParameters GetNormalizationParams();
  void SetNormalizationParams(NormalizationParameters params);
  void SetVertices(std::vector<float> vertices) { vertices_ = vertices; }
  void SetEdges(std::vector<size_t> edges) { edges_ = edges; }
  void TransformFigures(const TransformMatrix &matrix);
  std::vector<float> GetVertices() { return vertices_; }
  std::vector<size_t> GetEdges() { return edges_; }

private:
  std::vector<float> vertices_;
  std::vector<size_t> edges_;
  NormalizationParameters normalization_params_;
};

} // namespace s21

#endif // _3DVIEWER_MODEL_SCENE_H_
