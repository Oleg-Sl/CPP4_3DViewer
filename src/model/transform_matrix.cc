#include "transform_matrix.h"


TransformMatrix::TransformMatrix() {
    for (int row = 0; row <= matrix_size; ++row) {
        for (int col = 0; col <= matrix_size; ++col) {
            matrix[row][col] = (row == col) ? 1 : 0;
        }
    }
}

float& TransformMatrix::operator()(int row, int col) {
    if (row < 0 || row > matrix_size || col < 0 || col > matrix_size) {
        throw std::out_of_range("IndexError: matrix index out of range");
    }
    return matrix[row][col];
}

float TransformMatrix::operator()(int row, int col) const {
    if (row < 0 || row > matrix_size || col < 0 || col > matrix_size) {
        throw std::out_of_range("IndexError: matrix index out of range");
    }
    return matrix[row][col];
}

TransformMatrix TransformMatrix::operator*(const TransformMatrix& rhs_matrix) const {
    TransformMatrix result;
    for (int row = 0; row <= matrix_size; ++row) {
        for (int col = 0; col <= matrix_size; ++col) {
            result(row, col) = 0;
            for (int k = 0; k <= matrix_size; ++k) {
                result(row, col) += matrix[row][k] * rhs_matrix(k, col);
            }
        }
    }
    return result;
}

Point3D TransformMatrix::TransformPoint(const Point3D& point) const {
    Point3D result;
    result.x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    result.y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    result.z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    return result;
}
