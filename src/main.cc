
#include <QApplication>
#include <QDir>
#include <iostream>

#include "controller/include/controller.h"
#include "model/include/objreaderfast.h"
#include "model/include/scene.h"
#include "view/include/mainwindow.h"
#include "view/include/scenedrawer.h"

const QString kSettingsFileName = QString("settings.conf");

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QString settings_path =
      QDir::currentPath() + QString("/") + kSettingsFileName;

  s21::MySettings settings(settings_path, QSettings::IniFormat);
  s21::SceneDrawer scene_drawer;
  s21::OBJReaderFast reader;

  s21::Controller controller(reader, scene_drawer, settings);

  s21::MainWindow window(controller);

  window.show();
  return app.exec();
}
