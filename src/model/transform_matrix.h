#include "data.h"


#include <stdexcept>


class TransformMatrix {
public:
    static const n_dimensional = 3;

    TransformMatrix();
    TransformMatrix operator*(TransformMatrix m);
    float& operator()(int row, int col);
    Point3D TransformPoint(Point3D p);

private:
    float matrix[n_dimensional + 1][n_dimensional + 1];

};

