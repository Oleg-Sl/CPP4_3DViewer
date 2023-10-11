#ifndef _3DVIEWER_MODEL_VERTEX_H_
#define _3DVIEWER_MODEL_VERTEX_H_

#include "normalization_parameters.h"
#include "point3d.h"
#include "sceneobject.h"
#include "transform_matrix.h"

namespace s21 {

class Vertex : public SceneObject {
 public:
  Vertex(Point3D point);

  const Point3D& GetPosition() const;
  void SetPosition(Point3D new_position);

  void Transform(const TransformMatrix&);
  bool operator==(const Vertex& other);

 private:
  Point3D position_;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_VERTEX_H_
