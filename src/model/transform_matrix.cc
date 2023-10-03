#include "transform_matrix.h"


TransformMatrix::TransformMatrix() {
    for (int row = 0; row <= n_dimensional; ++row) {
        for (int col = 0; col <= n_dimensional; ++col) {
            matrix[row][col] = (row == col) ? 1 : 0;
        }
    }
}

float& TransformMatrix::operator()(int row, int col) {
    if (row < 0 || row > n_dimensional || col < 0 || col > n_dimensional) {
        throw std::out_of_range("IndexError: list index out of range");
    }
    return matrix[row][col];
}

TransformMatrix TransformMatrix::operator*(TransformMatrix other_matrix) {
    TransformMatrix result;
    for (int row = 0; row <= n_dimensional; ++row) {
        for (int col = 0; col <= n_dimensional; ++col) {
            float acc = 0;
            for (int k = 0; k <= n_dimensional; ++k) {
                acc += matrix[row][k] * other_matrix(k, col);
            }
            result[row][col] = acc;
        }
    }
    return result;
}

Point3D TransformMatrix::TransformPoint(Point3D other_point) {
    Point3D point;
    point.x = other_point.x * matrix[0][0] + other_point.y * matrix[0][1] + other_pointz * matrix[0][2];
    point.Y = other_point.x * matrix[1][0] + other_point.y * matrix[1][1] + other_pointz * matrix[1][2];
    point.z = other_point.x * matrix[2][0] + other_point.y * matrix[2][1] + other_pointz * matrix[2][2];
    return point;
}
