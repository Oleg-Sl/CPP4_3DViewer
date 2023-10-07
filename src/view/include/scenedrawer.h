#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_

#include "../include/scenedrawerbase.h"
#include "../model/include/scene.h"

#include <OpenGL/gl3.h>
#include <QColor>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

using namespace s21;

class SceneDrawer : public QOpenGLWidget,
                    protected QOpenGLFunctions,
                    public SceneDrawerBase {
  Q_OBJECT

public:
  SceneDrawer(QWidget *parent = nullptr);
  void DrawScene(Scene &);

protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

private:
  Scene scene;
};

#endif // _3DVIEWER_VIEW_INCLUDE_SCENE_BASE_H_
