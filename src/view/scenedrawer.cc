#include "include/scenedrawer.h"

#include "ui_mainwindow.h"
#include <QDebug>

namespace s21 {



SceneDrawer::SceneDrawer(QWidget *parent_) : QOpenGLWidget{parent_}, parent(parent_) {
   connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
   timer.start(100);
}

void SceneDrawer::DrawScene(Scene* new_scene) {
    scene = new_scene;
}

void SceneDrawer::SetParamsScene(SceneParameters* new_params) {
    scene_params = new_params;
}

void SceneDrawer::SetParentOpenGL(QWidget *parent) {
    setParent(parent);
    QVBoxLayout* layout = new QVBoxLayout(parent);
    layout->addWidget(this);
    layout->setContentsMargins(0, 0, 0, 0);
}


// https://runebook.dev/ru/docs/qt/qopenglwidget
void SceneDrawer::initializeGL() {
  QOpenGLWidget::initializeGL();
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void SceneDrawer::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (scene != nullptr && scene_params != nullptr) {
        SetBackgroundScene();

        SetTypeProjection();

        SetEdgesColor();
        SetEdgesWidth();
        SetEdgesType();

        RenderEdges();

        SetVerticesColor();
        SetVerticesSize();
        SetVerticesType();

        RenderVertices();
//       glFlush();

    }
}

void SceneDrawer::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void SceneDrawer::RenderVertices() {
    if (scene == nullptr) {
        return;
    }

    if (scene_params->vertex_type != SceneParameters::TypeVertex::kAbsent) {
//        glEnable(GL_POINTS);
        glBegin(GL_POINTS);
        for (auto figure : scene->GetFigures()) {
            for (auto vertex : figure.GetVertices()) {
                glVertex3f(vertex.GetPosition().x, vertex.GetPosition().y, vertex.GetPosition().z);
            }
        }
        glEnd();
//        glDisable(GL_POINTS);
    }
}

void SceneDrawer::RenderEdges() {
    if (scene == nullptr) {
        return;
    }

//    glEnable(GL_LINES);
    glBegin(GL_LINES);
    for (auto figure : scene->GetFigures()) {
        for (auto edge: figure.GetEdges()) {
            glVertex3f(edge.GetBegin().GetPosition().x, edge.GetBegin().GetPosition().y, edge.GetBegin().GetPosition().z);
            glVertex3f(edge.GetEnd().GetPosition().x, edge.GetEnd().GetPosition().y, edge.GetEnd().GetPosition().z);
        }
    }
    glEnd();
//    glDisable(GL_LINES);
}

void SceneDrawer::SetTypeProjection() {
    float value_max = 200;
    float value_min = -200;
    double ratio_x = width() > height() ? static_cast<float>(width()) / static_cast<float>(height()) : 1;
    double ratio_y = width() > height() ? 1 : static_cast<float>(height()) / static_cast<float>(width());
    if (scene_params->type_projection == SceneParameters::TypeProjection::kCentral) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        float fov = 60.0 * M_PI / 180;
        float tg_60 = tan(fov / 2);
        float heapHeight = 1.5 * value_max / tg_60;
        glFrustum(1.5 * tg_60 * value_min * ratio_x,
                  1.5 * tg_60 * value_max * ratio_x,
                  1.5 * tg_60 * value_min * ratio_y,
                  1.5 * tg_60 * value_max * ratio_y, heapHeight, 1);
        glTranslated(0.0f, 0.0f, -1.5 * value_max - 0.1);
        glMatrixMode(GL_MODELVIEW);
    } else if (scene_params->type_projection == SceneParameters::TypeProjection::kParallel) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(1.5 * value_min * ratio_x, 1.5 * value_max * ratio_x,
                1.5 * value_min * ratio_y, 1.5 * value_max * ratio_y, 5 * value_min,
                5 * value_max);
        glMatrixMode(GL_MODELVIEW);
    }

}

void SceneDrawer::SetBackgroundScene() {
    glClearColor(scene_params->background_color.redF(), scene_params->background_color.greenF(), scene_params->background_color.blueF(), scene_params->background_color.alphaF());
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
    glColor3f(scene_params->edge_color.redF(), scene_params->edge_color.greenF(), scene_params->edge_color.blueF());
}

void SceneDrawer::SetEdgesWidth() {
    glLineWidth(scene_params->edge_width);
}

void SceneDrawer::SetVerticesType() {
    if (scene_params->vertex_type == SceneParameters::TypeVertex::kCircle) {
        glEnable(GL_POINT_SMOOTH);
    } else if (scene_params->vertex_type == SceneParameters::TypeVertex::kSquare) {
        glDisable(GL_POINT_SMOOTH);
    }
}

void SceneDrawer::SetVerticesColor() {
    glColor3f(scene_params->vertex_color.redF(), scene_params->vertex_color.greenF(), scene_params->vertex_color.blueF());
}

void SceneDrawer::SetVerticesSize() {
    glPointSize(scene_params->vertex_size);
}

}
