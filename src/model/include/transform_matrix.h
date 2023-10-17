#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_

#include <stdexcept>
#include <iostream>
#include <vector>

#include "point3d.h"


namespace s21 {

class TransformMatrix {
 public:
  TransformMatrix();
  float& operator()(int row, int col);
  float operator()(int row, int col) const;
  TransformMatrix operator*(const TransformMatrix& rhs_matrix) const;
  void TransformVertices(std::vector<float> vertices) const;
  void TransformPoint(Point3D& point) const;

 private:
  float** matrix_ = nullptr;
  static const int matrix_size_ = 3;
//   float matrix_[matrix_size_ + 1][matrix_size_ + 1];
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
