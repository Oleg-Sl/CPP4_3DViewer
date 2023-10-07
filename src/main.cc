

#include "model/include/scene.h"
#include "model/include/filereader.h"
#include "view/include/mainwindow.h"

#include"view/include/scenedrawer.h"
#include <QApplication>
#include <iostream>
// namespace s21 {


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    s21::MainWindow w;

   s21::OBJReader reader;
   s21::Scene scene = reader.ReadScene("obj_examples/scull.obj");
   std::cout << "RESULT + " << scene.GetFigures().size();
//    s21::Scene scene = reader.ReadScene("obj_examples/cube.obj");

    //    s21::Scene scene;
    //    scene.AddFigure({
    //        s21::Point3D{ 0.5,  0.5, 0.5},
    //        s21::Point3D{ 0.5, -0.5, 0.5},
    //        s21::Point3D{-0.5, -0.5, 0.5},
    //        s21::Point3D{-0.5,  0.5, 0.5}
    //    });
    //    scene.AddFigure({
    //        s21::Point3D{ -0.2,  0.3, 0.4},
    //        s21::Point3D{ -0.2, 0.5, 0.5},
    //        s21::Point3D{0.4, -0.8, 0.5},
    //    });

    s21::SceneDrawer* widgetOpenGL = w.GetOpenglWidget();
    widgetOpenGL->DrawScene(scene);

    w.show();
    return a.exec();
// }

}
