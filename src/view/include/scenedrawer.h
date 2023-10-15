#ifndef _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_
#define _3DVIEWER_VIEW_INCLUDE_SCENE_DRAWER_H_

#include "scenedrawerbase.h"
#include "managersceneobserverbase.h"
#include "managerscenesubjectbase.h"
#include "sceneparameters.h"
#include "../model/include/scene.h"

#include <QColor>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLWidget>
#include <cmath>
#include <QTimer>

using namespace s21;


namespace s21 {

class SceneDrawer : public QOpenGLWidget, protected QOpenGLFunctions, public SceneDrawerBase {
  Q_OBJECT

public:
  SceneDrawer(QWidget *parent = nullptr);
  ~SceneDrawer() {}

  void SetScene(Scene*);
  void UpdateScene();
  void SetParamsScene(SceneParameters*);
  void SetParentOpenGL(QWidget *);

protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  void SetTypeProjection();
  void SetBackgroundScene();
  void SetEdgesType();
  void SetEdgesColor();
  void SetEdgesWidth();
  void RenderEdges();
  void SetVerticesType();
  void SetVerticesColor();
  void SetVerticesSize();
  void RenderVertices();

private:
  QWidget *parent;
  QTimer timer{};
  Scene *scene = nullptr;
  SceneParameters *scene_params = nullptr;

};

}

#endif  // _3DVIEWER_VIEW_INCLUDE_SCENE_BASE_H_
