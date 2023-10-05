#include "include/scenedrawer.h"

#include "ui_mainwindow.h"

SceneDrawer::SceneDrawer(QWidget* parent) : QOpenGLWidget{parent} {}

void SceneDrawer::DrawScene(Scene) {

}

void SceneDrawer::initializeGL() {
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_DEPTH_TEST);
}

// void paintGL() {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glBegin(GL_LINE_LOOP);
//         glVertex2i(0, 0);
//         glVertex2i(300, 300);
//         glVertex2i(0, 300);
//     glEnd();
// }

// void resizeGL(int w, int h) {
//     glViewport(0, 0, w, h);
// }

    // Scene scene;
    // scene.AddFigure({
    //     Point3D{ 0.5,  0.5, 0.5},
    //     Point3D{ 0.5, -0.5, 0.5}, 
    //     Point3D{-0.5, -0.5, 0.5},
    //     Point3D{-0.5,  0.5, 0.5}
    // });
