#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "managerscenesubjectbase.h"
#include "scenedrawer.h"
#include "sceneparameters.h"

#include <QColorDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow, public ManagerSceneSubjectBase {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QWidget *GetOpenglWidget();
  void Subscribe(ManagerSceneObservertBase *observer) override;
  void Unsubscribe(ManagerSceneObservertBase *observer) override;
  void Notify() override;

  enum TypeProjection { kCentral, kParallel };
  enum TypeEdges { kSolid, kDotted };
  enum TypeVertex { kAbsent, kCircle, kSquare };

private slots:
  void SlotChangeTypeProjection(int);
  void SlotChangeBackground();
  void SlotChangeEdgeType(int);
  void SlotChangeEdgeColor();
  void SlotChangeEdgeWidth(int);
  void SlotChangeVertexType(int);
  void SlotChangeVertexSize(int);
  void SlotChangeVertexColor();
  void SlotOpenFile();

private:
  Ui::MainWindow *ui;
  std::list<ManagerSceneObservertBase *> list_observer_;
  SceneParameters scene_params{};
  QString file_name;
};

} // namespace s21

#endif // MAINWINDOW_H
