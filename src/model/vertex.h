#ifndef _3DVIEWER_MODEL_VERTEX_H_
#define _3DVIEWER_MODEL_VERTEX_H_

#include "point_3d.h"
#include "scene_object.h"


class Vertex public SceneObject {
public:
    const Point3D& GetPosition() const;
    void Transform(const TransformMatrix& matrix);

private:
    Point3D position;
};

#endif  // _3DVIEWER_MODEL_VERTEX_H_
