#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scenedrawer.h"
#include "managerscenesubjectbase.h"
#include "sceneparameters.h"
#include "scenedrawer.h"
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

class MainWindow : public QMainWindow, public ManagerSceneSubjectBase {
  Q_OBJECT

public:
  MainWindow(Facade& cotroller, QWidget *parent = nullptr);
  ~MainWindow();

  QWidget *GetOpenglWidget();
  void Subscribe(ManagerSceneObservertBase *observer) override;
  void Unsubscribe(ManagerSceneObservertBase *observer) override;
  void Notify() override;
  // void SetParentWidgetForOpenGL(QWidget *);

  enum TypeProjection { kCentral, kParallel};
  enum TypeEdges { kSolid, kDotted };
  enum TypeVertex { kAbsent, kCircle, kSquare };
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
    std::list<ManagerSceneObservertBase *> list_observer_;
    SceneParameters scene_params{};

    VectorCoordinates previous_offsets{};
    VectorCoordinates previous_rotation{};
    VectorCoordinates previous_scales{};

//    TypeProjection type_projection{};
//    QColor background_color{};
//    TypeEdges edge_type{};
//    int edge_width{};
//    QColor edge_color{};
//    TypeVertex vertex_type{};
//    int vertex_size{};
//    QColor vertex_color{};

};

} // namespace s21

#endif // MAINWINDOW_H
