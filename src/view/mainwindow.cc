#include "include/mainwindow.h"

#include "../model/include/gifgenerator.h"
#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(Controller &ctrl, QWidget *parent)
    : QMainWindow(parent), controller(ctrl), ui(new Ui::MainWindow),

      scene_params(ctrl.GetSettings()) {
  ui->setupUi(this);

  InitSettings();
  InitSceneDraw();

  ui->screenPath->setText(screen_params.dir_path);
  ui->screenPath->setToolTip(screen_params.dir_path);

  ui->gifPath->setText(gif_params.gif_dir);
  ui->gifPath->setToolTip(gif_params.gif_dir);

  connect(ui->buttonSelectFile, SIGNAL(clicked()), this,
          SLOT(SlotSelectFile()));
  connect(ui->buttonRenderObj, SIGNAL(clicked()), this,
          SLOT(SlotRenderScene()));

  connect(ui->typeProjection, SIGNAL(activated(int)), this,
          SLOT(SlotChangeTypeProjection(int)));
  connect(ui->backgroundColor, SIGNAL(clicked()), this,
          SLOT(SlotChangeBackground()));
  connect(ui->lineType, SIGNAL(activated(int)), this,
          SLOT(SlotChangeEdgeType(int)));
  connect(ui->lineWidth, SIGNAL(valueChanged(int)), this,
          SLOT(SlotChangeEdgeWidth(int)));
  connect(ui->lineColor, SIGNAL(clicked()), this, SLOT(SlotChangeEdgeColor()));
  connect(ui->vertexType, SIGNAL(activated(int)), this,
          SLOT(SlotChangeVertexType(int)));
  connect(ui->vertexSize, SIGNAL(valueChanged(int)), this,
          SLOT(SlotChangeVertexSize(int)));
  connect(ui->vertexColor, SIGNAL(clicked()), this,
          SLOT(SlotChangeVertexColor()));

  connect(ui->moveX, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectX(int)));
  connect(ui->moveY, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectY(int)));
  connect(ui->moveZ, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectZ(int)));
  connect(ui->sliderMoveX, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectX(int)));
  connect(ui->sliderMoveY, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectY(int)));
  connect(ui->sliderMoveZ, SIGNAL(valueChanged(int)), this,
          SLOT(SlotMoveObjectZ(int)));

  connect(ui->rotateX, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectX(int)));
  connect(ui->rotateY, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectY(int)));
  connect(ui->rotateZ, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectZ(int)));
  connect(ui->sliderRotateX, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectX(int)));
  connect(ui->sliderRotateY, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectY(int)));
  connect(ui->sliderRotateZ, SIGNAL(valueChanged(int)), this,
          SLOT(SlotRotateObjectZ(int)));

  connect(ui->scale, SIGNAL(valueChanged(int)), this,
          SLOT(SlotScaleObjectXYZ(int)));
  connect(ui->sliderScale, SIGNAL(valueChanged(int)), this,
          SLOT(SlotScaleObjectXYZ(int)));

  connect(ui->screenPath, SIGNAL(clicked()), this,
          SLOT(SlotSelectScreenPath()));
  connect(ui->buttonPreentScreenBmp, SIGNAL(clicked()), this,
          SLOT(SlotPrintScreenBMP()));
  connect(ui->buttonPreentScreenJpeg, SIGNAL(clicked()), this,
          SLOT(SlotPrintScreenJPEG()));

  connect(ui->gifPath, SIGNAL(clicked()), this, SLOT(SlotSelectGifPath()));
  connect(ui->buttonCreateGif, SIGNAL(clicked()), this, SLOT(SlotMakeGif()));
}

MainWindow::~MainWindow() {
  controller.SetParentForSceneDraw(nullptr);
  delete ui;
}

void MainWindow::InitSettings() {
  ui->typeProjection->setCurrentIndex(scene_params.type_projection);
  ui->lineType->setCurrentIndex(static_cast<int>(scene_params.edge_type));
  ui->vertexType->setCurrentIndex(static_cast<int>(scene_params.vertex_type));
  ui->lineWidth->setValue(scene_params.edge_width);
  ui->vertexSize->setValue(scene_params.vertex_size);
  ui->lineColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                   .arg(scene_params.edge_color.red())
                                   .arg(scene_params.edge_color.green())
                                   .arg(scene_params.edge_color.blue()));
  ui->backgroundColor->setStyleSheet(
      QString("background-color: rgb(%1, %2, %3)")
          .arg(scene_params.background_color.red())
          .arg(scene_params.background_color.green())
          .arg(scene_params.background_color.blue()));
  ui->vertexColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                     .arg(scene_params.vertex_color.red())
                                     .arg(scene_params.vertex_color.green())
                                     .arg(scene_params.vertex_color.blue()));
}

void MainWindow::InitSceneDraw() {
  controller.SetParentForSceneDraw(ui->widgetOpenGL);
  controller.SetParamsScene(&scene_params);
}

void MainWindow::InitSceneParameters() {
  previous_offsets = {0, 0, 0};
  previous_rotation = {0, 0, 0};
  previous_scales = {100, 100, 100};
  ui->sliderMoveX->setSliderPosition(0);
  ui->moveX->setValue(0);
  ui->sliderMoveY->setSliderPosition(0);
  ui->moveY->setValue(0);
  ui->sliderMoveZ->setSliderPosition(0);
  ui->moveZ->setValue(0);
  ui->sliderRotateX->setSliderPosition(0);
  ui->rotateX->setValue(0);
  ui->sliderRotateY->setSliderPosition(0);
  ui->rotateY->setValue(0);
  ui->sliderRotateZ->setSliderPosition(0);
  ui->rotateZ->setValue(0);
  ui->sliderScale->setSliderPosition(100);
  ui->scale->setValue(100);
}

void MainWindow::Notify() {
  controller.UpdateSceneDraw();
  controller.UpdateSettings(scene_params);
}

void MainWindow::SlotSelectFile() {
  file_path =
      QFileDialog::getOpenFileName(this, "Open File", "./", tr("*.obj"));
  QFileInfo fileinfo(file_path);
  ui->fileName->setText(fileinfo.fileName());
}

void MainWindow::SlotRenderScene() {
  OperationResult result = controller.LoadScene(file_path);
  if (!result.is_success) {
    ShowMessage(QString::fromStdString(result.error_message), QColor(Qt::red));
    return;
  }
  ui->countVertexes->setText(QString::number(controller.GetCountVertices()));
  ui->countEdges->setText(QString::number(controller.GetCountEdges()));
  InitSceneParameters();
}

void MainWindow::SlotMoveObjectX(int offset) {
  if (offset == previous_offsets.x) {
    return;
  }
  controller.MoveScene((offset - previous_offsets.x), 0, 0);
  previous_offsets.x = offset;
  ui->sliderMoveX->setSliderPosition(offset);
  ui->moveX->setValue(offset);
}

void MainWindow::SlotMoveObjectY(int offset) {
  if (offset == previous_offsets.y) {
    return;
  }
  controller.MoveScene(0, offset - previous_offsets.y, 0);
  previous_offsets.y = offset;
  ui->sliderMoveY->setSliderPosition(offset);
  ui->moveY->setValue(offset);
}

void MainWindow::SlotMoveObjectZ(int offset) {
  if (offset == previous_offsets.z) {
    return;
  }
  controller.MoveScene(0, 0, offset - previous_offsets.z);
  previous_offsets.z = offset;
  ui->sliderMoveZ->setSliderPosition(offset);
  ui->moveZ->setValue(offset);
}

void MainWindow::SlotRotateObjectX(int angle_deg) {
  if (angle_deg == previous_rotation.x) {
    return;
  }
  controller.RotateScene((angle_deg - previous_rotation.x) * M_PI / 180, 0, 0);
  previous_rotation.x = angle_deg;
  ui->sliderRotateX->setSliderPosition(angle_deg);
  ui->rotateX->setValue(angle_deg);
}

void MainWindow::SlotRotateObjectY(int angle_deg) {
  if (angle_deg == previous_rotation.y) {
    return;
  }
  controller.RotateScene(0, (angle_deg - previous_rotation.y) * M_PI / 180, 0);
  previous_rotation.y = angle_deg;
  ui->sliderRotateY->setSliderPosition(angle_deg);
  ui->rotateY->setValue(angle_deg);
}

void MainWindow::SlotRotateObjectZ(int angle_deg) {
  if (angle_deg == previous_rotation.z) {
    return;
  }
  controller.RotateScene(0, 0, (angle_deg - previous_rotation.z) * M_PI / 180);
  previous_rotation.z = angle_deg;
  ui->sliderRotateZ->setSliderPosition(angle_deg);
  ui->rotateZ->setValue(angle_deg);
}

void MainWindow::SlotScaleObjectXYZ(int scale) {
  if (scale == previous_scales.x) {
    return;
  }
  controller.ScaleScene(scale / previous_scales.x, scale / previous_scales.y,
                        scale / previous_scales.z);
  previous_scales.x = scale;
  previous_scales.y = scale;
  previous_scales.z = scale;
  ui->sliderScale->setSliderPosition(scale);
  ui->scale->setValue(scale);
}

void MainWindow::SlotChangeTypeProjection(int ind_type_proj) {
  scene_params.type_projection =
      static_cast<SceneParameters::TypeProjection>(ind_type_proj);
  Notify();
}

void MainWindow::SlotChangeBackground() {
  QColor color = QColorDialog::getColor(scene_params.background_color);
  if (color.isValid()) {
    ui->backgroundColor->setStyleSheet(
        QString("background-color: rgb(%1, %2, %3)")
            .arg(color.red())
            .arg(color.green())
            .arg(color.blue()));
    scene_params.background_color = std::move(color);
    Notify();
  }
}

void MainWindow::SlotChangeEdgeType(int ind_edge_type) {
  scene_params.edge_type =
      static_cast<SceneParameters::TypeEdges>(ind_edge_type);
  Notify();
}

void MainWindow::SlotChangeVertexType(int ind_vertex_type) {
  scene_params.vertex_type =
      static_cast<SceneParameters::TypeVertex>(ind_vertex_type);
  Notify();
}

void MainWindow::SlotChangeEdgeWidth(int width) {
  scene_params.edge_width = width;
  Notify();
}

void MainWindow::SlotChangeVertexSize(int size) {
  scene_params.vertex_size = size;
  Notify();
}

void MainWindow::SlotChangeEdgeColor() {
  QColor color = QColorDialog::getColor(scene_params.edge_color);
  if (color.isValid()) {
    ui->lineColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                     .arg(color.red())
                                     .arg(color.green())
                                     .arg(color.blue()));
    scene_params.edge_color = std::move(color);
    Notify();
  }
}

void MainWindow::SlotChangeVertexColor() {
  QColor color = QColorDialog::getColor(scene_params.vertex_color);
  if (color.isValid()) {
    ui->vertexColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                       .arg(color.red())
                                       .arg(color.green())
                                       .arg(color.blue()));
    scene_params.vertex_color = std::move(color);
    Notify();
  }
}

void MainWindow::SlotSelectGifPath() {
  QString new_dir =
      QFileDialog::getExistingDirectory(0, "Выбор директории записи gif", "./");
  if (!new_dir.isEmpty()) {
    gif_params.gif_dir = new_dir;
    ui->gifPath->setText(gif_params.gif_dir);
    ui->gifPath->setToolTip(gif_params.gif_dir);
  }
}

void MainWindow::SlotSelectScreenPath() {
  QString new_dir = QFileDialog::getExistingDirectory(
      0, "Выбор директории записи скринов", "./");
  if (!new_dir.isEmpty()) {
    screen_params.dir_path = new_dir;
    ui->screenPath->setText(screen_params.dir_path);
    ui->screenPath->setToolTip(screen_params.dir_path);
  }
}

void MainWindow::SlotMakeGif() {
  ui->buttonCreateGif->setEnabled(false);
  gif_params.gif_before_time_left = gif_params.gif_before_time;
  PreparationMakingGif();
}

void MainWindow::PreparationMakingGif() {
  if (gif_params.gif_before_time_left <= 0) {
    StartMakingGif();
    return;
  }
  ShowMessage(QString("Запись GIF начнется через %1 сек.")
                  .arg(gif_params.gif_before_time_left * 0.001),
              QColor(30, 144, 255), 0);
  gif_params.gif_before_time_left -= 1000;
  QTimer::singleShot(1000, this, SLOT(PreparationMakingGif()));
}

void MainWindow::StartMakingGif() {
  ShowMessage(QString("Идет запись GIF"), QColor(39, 174, 96), 0);
  QString uniq_name =
      QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-z");
  gif_file_path = QString("%1/video_%2.gif").arg(gif_dir).arg(uniq_name);

  controller.CreateGif(gif_file_path.toStdString(), gif_params.gif_width,
                       gif_params.gif_height, gif_params.gif_fps,
                       gif_params.gif_duration / 10);
  CreateFrameToGif();
}

void MainWindow::CreateFrameToGif() {

  if (controller.AddGifFrame()) {
    ui->buttonCreateGif->setEnabled(true);
    ShowMessage(QString("Создана GIF: %1").arg(gif_file_path),
                QColor(50, 205, 50), 5000);
    return;
  }

  QTimer::singleShot(controller.GetGifDelay() * 10, this,
                     SLOT(CreateFrameToGif()));
}

void MainWindow::SlotPrintScreenBMP() { MakeScreenshot("bmp"); }

void MainWindow::SlotPrintScreenJPEG() { MakeScreenshot("jpeg"); }

void MainWindow::MakeScreenshot(QString extension) {
  QImage img = controller.GetFrameBuffer();
  QString uniq_name =
      QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-z");
  QString file_name = QString("%1/image_%2.%3")
                          .arg(screen_params.dir_path)
                          .arg(uniq_name)
                          .arg(extension);
  img.save(file_name);
  ShowMessage(QString("Создан снимок экрана: %1").arg(file_name),
              QColor(0, 128, 0), 5000);
}

void MainWindow::wheelEvent(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    ui->sliderScale->setSliderPosition(previous_scales.x + 5);
  } else {
    ui->sliderScale->setSliderPosition(previous_scales.x - 5);
  }
}

void MainWindow::ShowMessage(QString msg, QColor color, int message_timeout) {
  ui->statusbar->setStyleSheet(QString("color: " + color.name()));
  ui->statusbar->showMessage(msg);
  if (message_timeout > 0) {
    QTimer::singleShot(message_timeout, this, SLOT(ShowMessage()));
  }
}

} // namespace s21
