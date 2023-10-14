
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

    // s21::SceneDrawer* scene_drawer = new s21::SceneDrawer();
    // s21::OBJReader* reader = new s21::OBJReader();
    // s21::Facade* controller = new s21::Facade(*reader, *scene_drawer);
    // s21::MainWindow window(*controller);
    // delete controller;
    // delete reader;
    // delete scene_drawer;

    window.show();
    return app.exec();
}
