#ifndef _3DVIEWER_MODEL_TRANSFORM_MATRIX_BUILDER_H_
#define _3DVIEWER_MODEL_TRANSFORM_MATRIX_BUILDER_H_

#include "point_3d.h"
#include "transform_matrix.h"

#include <cmath>

class TransformMatrixBuilder {
    static TransformMatrix CreateRotationMatrix(float x, float y, float z);
    static TransformMatrix CreateMoveMatrix(float x, float y, float z);
    static TransformMatrix CreateScaleMatrix(float x, float y, float z);
};

#endif  // _3DVIEWER_MODEL_TRANSFORM_MATRIX_BUILDER_H_
