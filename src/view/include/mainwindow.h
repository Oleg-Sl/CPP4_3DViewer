#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scenedrawer.h"
#include "managerscenesubjectbase.h"
#include "sceneparameters.h"
#include "../../controller/include/facade.h"
#include "cmath"

#include "../../lib/gif.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QMouseEvent>
#include <QDir>
#include <QDateTime>
#include <QTimer>


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


//    bool eventFilter(QObject *, QEvent *);
    void wheelEvent(QWheelEvent *);
//    void mousePressEvent(QMouseEvent *);
//    void mouseMoveEvent(QMouseEvent *);
    void PreparationMakingGif();
    void StartMakingGif();
    void MakeScreenshot(QString );
    void CreateFrameToGif();
    void ShowMessage(QString msg = "", QColor color = QColor(Qt::black), int message_timeout = 0);

private:
    Facade& controller;
    Ui::MainWindow *ui;
    SceneParameters scene_params;
    QString file_path;
    QString screen_dir = QDir("./").absolutePath();
    QString gif_dir = QDir("./").absolutePath();
    QString gif_file_path;
    int gif_before_time = 5000;
    int gif_before_time_left = 5000;
    int gif_time = 5000;
    int gif_time_left = 5000;
    int gif_delay = 100;
    int gif_width = 640;
    int gif_height = 480;

    GifWriter g{};
    int count_frames = 0;

    VectorCoordinates previous_offsets{};
    VectorCoordinates previous_rotation{};
    VectorCoordinates previous_scales{100, 100, 100};

    int mouse_event_x{};
    int mouse_event_y{};
    void InitSettings();
};

} // namespace s21

#endif // MAINWINDOW_H
