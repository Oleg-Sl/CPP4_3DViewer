#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include <vector>
#include <ctime>
#include <QDebug>

#include "figure.h"
#include "transform_matrix.h"

namespace s21 {

class Scene {
public:
  std::vector<Figure> &GetFigures();
  void TransformFigures(const TransformMatrix &);
  void AddFigure(Figure &&figure);
  NormalizationParameters GetNormalizationParams();
  void SetNormalizationParams(NormalizationParameters params);

private:
  std::vector<Figure> figures_;
  size_t edges_count_ = 0;
  size_t verticies_count_ = 0;
  NormalizationParameters normalization_params_;
};

} // namespace s21

#endif // _3DVIEWER_MODEL_SCENE_H_
