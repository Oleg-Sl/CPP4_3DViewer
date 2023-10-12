
#include <QApplication>
#include <iostream>

#include "model/include/objreader.h"
#include "model/include/scene.h"
#include "view/include/mainwindow.h"
#include "view/include/scenedrawer.h"

#include "controller/include/facade.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    s21::SceneDrawer scene_drawer;
    s21::OBJReader reader;
    s21::Facade controller(reader, scene_drawer);

    s21::MainWindow window(controller);

    // scene_drawer.SetParentOpenGL(window.GetOpenglWidget());
    // scene_drawer.SetParentOpenGL(nullptr);

    // s21::SceneDrawer scene_drawer(window.GetOpenglWidget(), window);
    // Facade controller(reader, scene_drawer);

    window.show();
    return app.exec();
}
