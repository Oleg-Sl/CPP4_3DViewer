#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include <vector>
#include <ctime>
#include <QDebug>

#include "bounds.h"
#include "figure.h"
#include "transform_matrix.h"

namespace s21 {

class Scene {
 public:
  std::vector<Figure> &GetFigures();
  void TransformFigures(const TransformMatrix &);
  void AddFigure(Figure &&figure);
  void SetBounds(Bounds bounds);
  const Bounds &GetBounds();

 private:
  std::vector<Figure> figures_;
  size_t edges_count = 0;
  size_t verticies_count = 0;
  Bounds bounds_;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_SCENE_H_
