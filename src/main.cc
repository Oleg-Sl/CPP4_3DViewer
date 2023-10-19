
#include <QApplication>
#include <QDir>
#include <iostream>

#include "controller/include/facade.h"
#include "model/include/objreader.h"
#include "model/include/scene.h"
#include "view/include/mainwindow.h"
#include "view/include/scenedrawer.h"

const QString SETTINGS_FILE_NAME = QString("settings.conf");

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QString settings_path =
      QDir::currentPath() + QString("/") + SETTINGS_FILE_NAME;

  s21::MySettings settings(settings_path, QSettings::IniFormat);
  s21::SceneDrawer scene_drawer;
  s21::OBJReader reader;
  s21::Facade controller(reader, scene_drawer, settings);

  s21::MainWindow window(controller);

  window.show();
  return app.exec();
}
