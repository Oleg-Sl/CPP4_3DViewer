#include "include/scenedrawer.h"

#include "ui_mainwindow.h"
#include <QDebug>

SceneDrawer::SceneDrawer(QWidget* parent) : QOpenGLWidget{parent}, scene() {

            // Setup scene and render it
//            initializeGL();
//            paintGL();
//    initializeOpenGLFunctions();
//    setSurfaceType(OpenGLSurface);
//            create();

//            // Create an OpenGL context
//            m_context = new QOpenGLContext;
//            m_context->create();

//            // Setup scene and render it
//            initializeGL();
//            paintGL();
}

void SceneDrawer::DrawScene(Scene& new_scene) {
    std::swap(scene, new_scene);
//    scene = new_scene;
    update();
 //

}

//https://runebook.dev/ru/docs/qt/qopenglwidget
void SceneDrawer::initializeGL() {
    QOpenGLWidget::initializeGL();
    initializeOpenGLFunctions();
    // цвет фона
    glClearColor(1,1,1,0.5);
    // цвет линий
    glColor3f(0, 1, 0);
}

 void SceneDrawer::paintGL() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(0, 1, 1);

     for (auto figure : scene.GetFigures()) {
         glBegin(GL_LINE_LOOP);
         for (auto vertex : figure.GetVertices()) {
             qDebug() << vertex.GetPosition().x << " - " << vertex.GetPosition().y << " - " << vertex.GetPosition().z;
             glVertex3f(vertex.GetPosition().x, vertex.GetPosition().y, vertex.GetPosition().z);
         }
         glEnd();
     }
 }

 void SceneDrawer::resizeGL(int w, int h) {
     glViewport(0, 0, w, h);
 }

 //


 //     Scene scene;
 //     scene.AddFigure({
 //         Point3D{ 0.5,  0.5, 0.5},
 //         Point3D{ 0.5, -0.5, 0.5},
 //         Point3D{-0.5, -0.5, 0.5},
 //         Point3D{-0.5,  0.5, 0.5}
 //     });
 //    DrawScene(scene);


 //     //     glClearColor(0,0,1,0.5);
 //     //     glColor3f(i, i, i);
 //     glPointSize(10);
 //     glBegin(GL_POINTS);
 //         glVertex2f(i, 0);
 //         glVertex2f(0.5, 0.5);
 //         glVertex2f(0, 0.5);
 //     glEnd();
 //          glLineWidth(2);
 //     glBegin(GL_LINE_LOOP);
 //         glVertex2f(i, 0);
 //         glVertex2f(0.5, 0.5);
 //         glVertex2f(0, 0.5);
 //     glEnd();

 //     glBegin(GL_LINE_LOOP);
 //         glVertex2i(0, 0);
 //         glVertex2i(-1, -1);
 //         glVertex2i(0, -1);
 //     glEnd();
 //     glVertex2i(0, 0);
 //     glVertex2i(-1, -1);
 //     glVertex2i(0, -1);
 //     glPointSize(1011);

