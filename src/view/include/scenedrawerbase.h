#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_

#include "../model/include/scene.h"


namespace s21 {

class SceneDrawerBase {
public:
    virtual void DrawScene(Scene&) = 0;
};

}

#endif  // _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_
