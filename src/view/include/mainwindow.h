#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMouseEvent>

#include "../../controller/include/facade.h"
#include "cmath"
#include "managerscenesubjectbase.h"
#include "scenedrawer.h"
#include "sceneparameters.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Facade &cotroller, QWidget *parent = nullptr);
  ~MainWindow();

  void Notify();
  struct VectorCoordinates {
    float x{};
    float y{};
    float z{};
  };

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
  //    bool eventFilter(QObject *, QEvent *);
  void wheelEvent(QWheelEvent *);
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);

 private:
  Facade &controller;
  Ui::MainWindow *ui;
  SceneParameters scene_params;
  QString file_path;

  VectorCoordinates previous_offsets{};
  VectorCoordinates previous_rotation{};
  VectorCoordinates previous_scales{100, 100, 100};

  int mouse_event_x{};
  int mouse_event_y{};
  void InitSettings();
};

}  // namespace s21

#endif  // MAINWINDOW_H
