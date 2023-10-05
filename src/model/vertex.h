#ifndef _3DVIEWER_MODEL_VERTEX_H_
#define _3DVIEWER_MODEL_VERTEX_H_

#include "scene_object.h"
#include "transform_matrix.h"
#include "point_3d.h"



class Vertex : public SceneObject {
public:
    Vertex(Point3D point);
    const Point3D& GetPosition() const;
    void Transform(const TransformMatrix&);

private:
    Point3D position;
};

#endif  // _3DVIEWER_MODEL_VERTEX_H_
