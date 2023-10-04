#ifndef _3DVIEWER_MODEL_SCENE_OBJECT_H_
#define _3DVIEWER_MODEL_SCENE_OBJECT_H_

#include "transform_matrix.h"


class SceneObject {
    virtual void Transform(TransformMatrix) = 0;
};

#endif  // _3DVIEWER_MODEL_SCENE_OBJECT_H_
