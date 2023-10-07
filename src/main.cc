#include "../view/include/mainwindow.h"
#include "model/include/scene.h"
#include "model/include/filereader.h"
#include "view/include/scenedrawer.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[]) {

  using namespace s21;

  QApplication a(argc, argv);
  MainWindow w;

  OBJReader reader;
  Scene scene = reader.ReadScene("/Users/varlybot/Desktop/CPP4_3DViewer_v2.0-1/src/obj_examples/cube.obj");
  // std::cout << "СЦЕНА: " << scene.GetFigures().size() << std::endl;
  scene.GetFigures().at(0).PrintEdges();

  SceneDrawer *widgetOpenGL = w.GetOpenglWidget();
  widgetOpenGL->DrawScene(scene);

  w.show();
  return a.exec();
}
