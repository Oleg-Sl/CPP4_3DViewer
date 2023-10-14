#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scenedrawer.h"
#include "managerscenesubjectbase.h"
#include "sceneparameters.h"
#include "../../controller/include/facade.h"
#include "cmath"

#include <QMainWindow>
#include <QColorDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(Facade& cotroller, QWidget *parent = nullptr);
  ~MainWindow();

  void Notify();

  struct VectorCoordinates {
    float x{};
    float y{};
    float z{};
  };

private slots:
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

private:
    Facade& controller;
    Ui::MainWindow *ui;
    SceneParameters scene_params{};

    VectorCoordinates previous_offsets{};
    VectorCoordinates previous_rotation{};
    VectorCoordinates previous_scales{100, 100, 100};

};

} // namespace s21

#endif // MAINWINDOW_H
