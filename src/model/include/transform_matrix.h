#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_

#include <stdexcept>

#include "point_3d.h"

namespace s21 {

class TransformMatrix {
 public:
  TransformMatrix();
  float& operator()(int row, int col);
  float operator()(int row, int col) const;
  TransformMatrix operator*(const TransformMatrix& rhs_matrix) const;
  Point3D TransformPoint(const Point3D& point) const;

 private:
  static const int matrix_size_ = 3;
  float matrix_[matrix_size_ + 1][matrix_size_ + 1];
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
