#include "include/transform_matrix.h"

namespace s21 {
TransformMatrix::TransformMatrix() {
  matrix_ = new float*[4];
  for (int i = 0; i < 4; i++) {
    matrix_[i] = new float[4];
    for (int j = 0; j < 4; j++) {
      matrix_[i][j] = 0.0f;
    }
  }

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

void TransformMatrix::TransformVertices(std::vector<float> vertices) const {
  for (int i = 0; i + 3 < vertices.size(); i += 3) {
    float x = vertices[i] * matrix_[0][0] + vertices[i + 1] * matrix_[0][1] + vertices[i + 2] * matrix_[0][2] + matrix_[0][3];
    float y = vertices[i] * matrix_[1][0] + vertices[i + 1] * matrix_[1][1] + vertices[i + 2] * matrix_[1][2] + matrix_[1][3];
    float z = vertices[i] * matrix_[2][0] + vertices[i + 1] * matrix_[2][1] + vertices[i + 2] * matrix_[2][2] + matrix_[2][3];
    vertices[i] = std::move(x);
    vertices[i + 1] = std::move(y);
    vertices[i + 2] = std::move(z);
  }
}

void TransformMatrix::TransformPoint(Point3D& point) const {
  float x = point.x * matrix_[0][0] + point.y * matrix_[0][1] + point.z * matrix_[0][2] + matrix_[0][3];
  float y = point.x * matrix_[1][0] + point.y * matrix_[1][1] + point.z * matrix_[1][2] + matrix_[1][3];
  float z = point.x * matrix_[2][0] + point.y * matrix_[2][1] + point.z * matrix_[2][2] + matrix_[2][3];
  point.x = std::move(x);
  point.y = std::move(y);
  point.z = std::move(z);
}

}  // namespace s21
