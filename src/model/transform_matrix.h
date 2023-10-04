#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_

#include "point_3d.h"

#include <stdexcept>


class TransformMatrix {
public:
    static const int n_dimensional = 3;

    TransformMatrix();
    TransformMatrix operator*(TransformMatrix m);
    float& operator()(int row, int col);
    Point3D TransformPoint(Point3D p);

private:
    float matrix[n_dimensional + 1][n_dimensional + 1];

};

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_H_
