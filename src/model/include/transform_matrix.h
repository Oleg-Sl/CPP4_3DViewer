#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_

#include <vector>

namespace s21 {

class TransformMatrix {
 public:
  TransformMatrix();
  float& operator()(int row, int col);
  float operator()(int row, int col) const;
  TransformMatrix operator*(const TransformMatrix& rhs_matrix) const;
  void TransformVertices(std::vector<float>& vertices) const;

 private:
  float matrix_[4][4];
  static const int matrix_size_ = 3;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
