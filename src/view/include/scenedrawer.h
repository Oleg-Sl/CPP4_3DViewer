#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_

#include "../model/scene.h"
#include "../include/scenedrawerbase.h"


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QColor>
#include <GL/gl.h>


class SceneDrawer : public QOpenGLWidget, protected QOpenGLFunctions, public SceneDrawerBase {
  Q_OBJECT

public:
    SceneDrawer(QWidget* parent = nullptr);
    void DrawScene(Scene&);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    Scene scene;

};




#endif  // _3DVIEWER_VIEW_INCLUDE_SCENE_BASE_H_
