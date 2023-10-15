#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_

#include "../model/include/scene.h"
#include "sceneparameters.h"

#include <QOpenGLWidget>


namespace s21 {

class SceneDrawerBase {
public:
    virtual void UpdateScene() = 0;
    virtual void SetScene(Scene*) = 0;
    virtual void SetParamsScene(SceneParameters*) = 0;
    virtual void SetParentOpenGL(QWidget *) = 0;
    virtual QImage GetFrameBuffer() = 0;
};

}

#endif  // _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_BASE_H_
