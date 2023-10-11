
#include <QApplication>
#include <iostream>

#include "model/include/objreader.h"
#include "model/include/scene.h"
#include "view/include/mainwindow.h"
#include "view/include/scenedrawer.h"
// namespace s21 {

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  s21::MainWindow w;

  s21::OBJReader reader;
  s21::Scene scene = reader.ReadScene(
      "/home/alexander/Desktop/school/CPP4_3DViewer_v2.0-1/src/obj_examples/"
      "man.obj",
      {-0.5, 0.5});
  Figure figure;
  figure.AddVertex(Vertex({-0.5, 0.5, 0.5}));
  figure.AddVertex(Vertex({0.5, 0.5, 0.5}));
  figure.AddVertex(Vertex({0.5, -0.5, 0.5}));
  figure.AddVertex(Vertex({-0.5, -0.5, 0.5}));
  figure.AddEdge(0, 1);
  figure.AddEdge(1, 2);
  figure.AddEdge(2, 3);
  figure.AddEdge(3, 0);
  scene.AddFigure(std::move(figure));
  // s21::Scene scene =
  // reader.ReadScene("/home/oleg/school21/CPP4_3DViewer_v2.0-1/src/obj_examples/skull.obj");
  s21::SceneDrawer* widgetOpenGL = new SceneDrawer(w.GetOpenglWidget(), w);

  widgetOpenGL->DrawScene(scene);

  w.show();
  return a.exec();
}
