
#include "../view/include/mainwindow.h"
#include "model/scene.h"
#include"view/include/scenedrawer.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

        Scene scene;
        scene.AddFigure({
            Point3D{ 0.5,  0.5, 0.5},
            Point3D{ 0.5, -0.5, 0.5},
            Point3D{-0.5, -0.5, 0.5},
            Point3D{-0.5,  0.5, 0.5}
        });
        scene.AddFigure({
            Point3D{ -0.2,  0.3, 0.4},
            Point3D{ -0.2, 0.5, 0.5},
            Point3D{0.4, -0.8, 0.5},
        });

    SceneDrawer* widgetOpenGL = w.GetOpenglWidget();
    widgetOpenGL->DrawScene(scene);

    w.show();
    return a.exec();
}

