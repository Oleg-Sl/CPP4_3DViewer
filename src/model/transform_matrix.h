#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_

#include "point_3d.h"

#include <stdexcept>


class TransformMatrix {
public:
    TransformMatrix();
    float& operator()(int row, int col);
    float operator()(int row, int col) const;
    TransformMatrix operator*(const TransformMatrix& rhs_matrix) const;
    Point3D TransformPoint(const Point3D& point) const;

private:
    static const int matrix_size = 3;
    float matrix[matrix_size + 1][matrix_size + 1];
};

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
