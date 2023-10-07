#ifndef _3DVIEWER_MODEL_SCENE_OBJECT_H_
#define _3DVIEWER_MODEL_SCENE_OBJECT_H_

#include "transform_matrix.h"

namespace s21 {

class SceneObject {
  virtual void Transform(const TransformMatrix&) = 0;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_SCENE_OBJECT_H_
