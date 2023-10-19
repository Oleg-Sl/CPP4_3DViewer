#include "include/scenedrawer.h"

#include <QDebug>

#include "ui_mainwindow.h"

namespace s21 {

SceneDrawer::SceneDrawer(QWidget *parent_)
    : QOpenGLWidget{parent_}, parent(parent_) {
  //   connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
  //   timer.start(100);
}

void SceneDrawer::UpdateScene() { update(); }

void SceneDrawer::SetScene(Scene *new_scene) { scene = new_scene; }

void SceneDrawer::SetParamsScene(SceneParameters *new_params) {
  scene_params = new_params;
}

void SceneDrawer::SetParentOpenGL(QWidget *parent) {
  setParent(parent);
  QVBoxLayout *layout = new QVBoxLayout(parent);
  layout->addWidget(this);
  layout->setContentsMargins(0, 0, 0, 0);
}

QImage SceneDrawer::GetFrameBuffer() { return grabFramebuffer(); }

void SceneDrawer::initializeGL() {
  QOpenGLWidget::initializeGL();
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void SceneDrawer::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  SetBackgroundScene();

  if (scene != nullptr && scene_params != nullptr) {
    SetTypeProjection();

    SetEdgesColor();
    SetEdgesWidth();
    SetEdgesType();

    RenderEdges();

    SetVerticesColor();
    SetVerticesSize();
    SetVerticesType();

    RenderVertices();
  }
}

void SceneDrawer::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void SceneDrawer::RenderVertices() {
  if (scene == nullptr) {
    return;
  }
  if (scene_params->vertex_type != SceneParameters::TypeVertex::kAbsent) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, scene->GetVertices().data());

    glDrawArrays(GL_POINTS, 0, scene->GetVertices().size() / 3);

    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void SceneDrawer::RenderEdges() {
  if (scene == nullptr) {
    return;
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, scene->GetVertices().data());

  glDrawElements(GL_LINES, scene->GetEdges().size(), GL_UNSIGNED_INT,
                 scene->GetEdges().data());

  glDisableClientState(GL_VERTEX_ARRAY);
}

void SceneDrawer::SetTypeProjection() {
  float value_max = scene->GetNormalizationParams().max;
  float value_min = -scene->GetNormalizationParams().max;

  double ratio_x = width() > height() ? static_cast<float>(width()) /
                                            static_cast<float>(height())
                                      : 1;
  double ratio_y = width() > height() ? 1
                                      : static_cast<float>(height()) /
                                            static_cast<float>(width());
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (scene_params->type_projection ==
      SceneParameters::TypeProjection::kCentral) {
    float fov = 60.0 * M_PI / 180;
    float tg_60 = tan(fov / 2);
    float heapHeight = 1.5 * value_max / tg_60;
    glFrustum(1.5 * tg_60 * value_min * ratio_x,
              1.5 * tg_60 * value_max * ratio_x,
              1.5 * tg_60 * value_min * ratio_y,
              1.5 * tg_60 * value_max * ratio_y, heapHeight, 1);
    glTranslated(0.0f, 0.0f, -1.5 * value_max - 0.1);
  } else if (scene_params->type_projection ==
             SceneParameters::TypeProjection::kParallel) {
    glOrtho(1.5 * value_min * ratio_x, 1.5 * value_max * ratio_x,
            1.5 * value_min * ratio_y, 1.5 * value_max * ratio_y, 5 * value_min,
            5 * value_max);
  }
  
  glMatrixMode(GL_MODELVIEW);
}

void SceneDrawer::SetBackgroundScene() {
  if (scene_params != nullptr) {
    glClearColor(scene_params->background_color.redF(),
                 scene_params->background_color.greenF(),
                 scene_params->background_color.blueF(),
                 scene_params->background_color.alphaF());
  }
}

void SceneDrawer::SetEdgesType() {
  if (scene_params->edge_type == SceneParameters::TypeEdges::kSolid) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  } else if (scene_params->edge_type == SceneParameters::TypeEdges::kDotted) {
    glDisable(GL_LINE_STIPPLE);
  }
}

void SceneDrawer::SetEdgesColor() {
  glColor3f(scene_params->edge_color.redF(), scene_params->edge_color.greenF(),
            scene_params->edge_color.blueF());
}

void SceneDrawer::SetEdgesWidth() { glLineWidth(scene_params->edge_width); }

void SceneDrawer::SetVerticesType() {
  if (scene_params->vertex_type == SceneParameters::TypeVertex::kCircle) {
    glEnable(GL_POINT_SMOOTH);
  } else if (scene_params->vertex_type ==
             SceneParameters::TypeVertex::kSquare) {
    glDisable(GL_POINT_SMOOTH);
  }
}

void SceneDrawer::SetVerticesColor() {
  glColor3f(scene_params->vertex_color.redF(),
            scene_params->vertex_color.greenF(),
            scene_params->vertex_color.blueF());
}

void SceneDrawer::SetVerticesSize() { glPointSize(scene_params->vertex_size); }

} // namespace s21
