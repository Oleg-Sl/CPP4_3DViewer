#include "include/transform_matrix.h"

namespace s21 {
TransformMatrix::TransformMatrix() {
  for (int row = 0; row <= matrix_size_; ++row) {
    for (int col = 0; col <= matrix_size_; ++col) {
      matrix_[row][col] = (row == col) ? 1 : 0;
    }
  }
}

float& TransformMatrix::operator()(int row, int col) {
  if (row < 0 || row > matrix_size_ || col < 0 || col > matrix_size_) {
    throw std::out_of_range("IndexError: matrix index out of range");
  }
  return matrix_[row][col];
}

float TransformMatrix::operator()(int row, int col) const {
  if (row < 0 || row > matrix_size_ || col < 0 || col > matrix_size_) {
    throw std::out_of_range("IndexError: matrix index out of range");
  }
  return matrix_[row][col];
}

TransformMatrix TransformMatrix::operator*(
    const TransformMatrix& rhs_matrix) const {
  TransformMatrix result;
  for (int row = 0; row <= matrix_size_; ++row) {
    for (int col = 0; col <= matrix_size_; ++col) {
      result(row, col) = 0;
      for (int k = 0; k <= matrix_size_; ++k) {
        result(row, col) += matrix_[row][k] * rhs_matrix(k, col);
      }
    }
  }
  return result;
}

Point3D TransformMatrix::TransformPoint(const Point3D& point) const {
  Point3D result;
  result.x =
      point.x * matrix_[0][0] + point.y * matrix_[0][1] + point.z * matrix_[0][2];
  result.y =
      point.x * matrix_[1][0] + point.y * matrix_[1][1] + point.z * matrix_[1][2];
  result.z =
      point.x * matrix_[2][0] + point.y * matrix_[2][1] + point.z * matrix_[2][2];
  return result;
}

}  // namespace s21