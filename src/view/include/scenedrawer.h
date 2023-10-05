#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_

#include "../model/scene.h"
#include "../include/scenedrawerbase.h"

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>


class SceneDrawer : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

public:
    SceneDrawer(QWidget* parent = nullptr);
    void DrawScene(Scene);


// protected:
   void initializeGL();
   // void paintGL();
   // void resizeGL(int w, int h);

private:

};




#endif  // _3DVIEWER_VIEW_INCLUDE_SCENE_BASE_H_
