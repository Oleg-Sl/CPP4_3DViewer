#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include <vector>

#include "figure.h"
#include "transform_matrix.h"

namespace s21 {

class Scene {
 public:
  std::vector<Figure> &GetFigures();
  void TransformFigures(const TransformMatrix &);
  void AddFigure(const Figure &figure);

 private:
  std::vector<Figure> figures_;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_SCENE_H_
