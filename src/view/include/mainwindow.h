#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>

#include "../../controller/include/controller.h"
#include "../../lib/gif.h"
#include "cmath"
#include "managerscenesubjectbase.h"
#include "scenedrawer.h"
#include "sceneparameters.h"

    QT_BEGIN_NAMESPACE namespace Ui {
  class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(Controller &cotroller, QWidget *parent = nullptr);
  ~MainWindow();


private:
  struct VectorCoordinates {
    float x{};
    float y{};
    float z{};
  };
  struct ScreenParameters {
      QString file_path;
      QString dir_path = QDir("./").absolutePath();
  };
  struct GifParameters {
      QString gif_dir{QDir("./").absolutePath()};
      QString gif_file_path{};
      int gif_before_time{5000};
      int gif_before_time_left{};
      int gif_time{5000};
      int gif_time_left{};
      int gif_delay{100};
      int gif_width{640};
      int gif_height{480};
      bool is_record{false};
  };

  void Notify();

private slots:
  void SlotRenderScene();
  void SlotSelectFile();

  void SlotChangeTypeProjection(int);
  void SlotChangeBackground();
  void SlotChangeEdgeType(int);
  void SlotChangeEdgeColor();
  void SlotChangeEdgeWidth(int);
  void SlotChangeVertexType(int);
  void SlotChangeVertexSize(int);
  void SlotChangeVertexColor();
  void SlotMoveObjectX(int);
  void SlotMoveObjectY(int);
  void SlotMoveObjectZ(int);
  void SlotRotateObjectX(int);
  void SlotRotateObjectY(int);
  void SlotRotateObjectZ(int);
  void SlotScaleObjectXYZ(int);

  void SlotSelectGifPath();
  void SlotSelectScreenPath();
  void SlotMakeGif();
  void SlotPrintScreenBMP();
  void SlotPrintScreenJPEG();

  void wheelEvent(QWheelEvent *);
  void PreparationMakingGif();
  void StartMakingGif();
  void MakeScreenshot(QString);
  void CreateFrameToGif();
  void ShowMessage(QString msg = "", QColor color = QColor(Qt::black), int message_timeout = 0);

private:
  Controller &controller;
  Ui::MainWindow *ui;
  SceneParameters scene_params;
  ScreenParameters screen_params;
  GifParameters gif_params;

  QTimer timer{};
  GifWriter g{};

  VectorCoordinates previous_offsets{};
  VectorCoordinates previous_rotation{};
  VectorCoordinates previous_scales{100, 100, 100};

  int mouse_event_x{};
  int mouse_event_y{};

  void InitSettings();
  void InitSceneDraw();
  void InitSceneParameters();
};

} // namespace s21

#endif // MAINWINDOW_H
