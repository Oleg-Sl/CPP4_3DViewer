#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->typeProjection,  SIGNAL(activated(int)),    this, SLOT(SlotChangeTypeProjection(int)));
    connect(ui->backgroundColor, SIGNAL(clicked()),         this, SLOT(SlotChangeBackground()));
    connect(ui->lineType,        SIGNAL(activated(int)),    this, SLOT(SlotChangeEdgeType(int)));
    connect(ui->lineWidth,       SIGNAL(valueChanged(int)), this, SLOT(SlotChangeEdgeWidth(int)));
    connect(ui->lineColor,       SIGNAL(clicked()),         this, SLOT(SlotChangeEdgeColor()));
    connect(ui->vertexType,      SIGNAL(activated(int)),    this, SLOT(SlotChangeVertexType(int)));
    connect(ui->vertexSize,      SIGNAL(valueChanged(int)), this, SLOT(SlotChangeVertexSize(int)));
    connect(ui->vertexColor,     SIGNAL(clicked()),         this, SLOT(SlotChangeVertexColor()));
    connect(ui->buttonSelectFile,     SIGNAL(clicked()),         this, SLOT(SlotOpenFile()));
}

MainWindow::~MainWindow() { delete ui; }

QWidget *MainWindow::GetOpenglWidget() {
  return ui->widgetOpenGL;
}

void MainWindow::Subscribe(ManagerSceneObservertBase *observer) {
  list_observer_.push_back(observer);
}

void MainWindow::Unsubscribe(ManagerSceneObservertBase *observer) {
  list_observer_.remove(observer);
}

void MainWindow::Notify() {
  for (auto observer : list_observer_) {
    observer->Update(scene_params);
  }
}

void MainWindow::SlotChangeTypeProjection(int ind_type_proj) {
    scene_params.type_projection = static_cast<SceneParameters::TypeProjection>(ind_type_proj);
    Notify();
}

void MainWindow::SlotChangeBackground() {
    QColor color = QColorDialog::getColor(scene_params.background_color);
    if (color.isValid()) {
        ui->backgroundColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        scene_params.background_color = std::move(color);
        Notify();
    }
}

void MainWindow::SlotChangeEdgeType(int ind_edge_type) {
    scene_params.edge_type = static_cast<SceneParameters::TypeEdges>(ind_edge_type);
    Notify();
}

void MainWindow::SlotChangeVertexType(int ind_vertex_type) {
    scene_params.vertex_type = static_cast<SceneParameters::TypeVertex>(ind_vertex_type);
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
        ui->lineColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        scene_params.edge_color = std::move(color);
        Notify();
    }
}

void MainWindow::SlotChangeVertexColor() {
    QColor color = QColorDialog::getColor(scene_params.vertex_color);
    if (color.isValid()) {
        ui->vertexColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        scene_params.vertex_color = std::move(color);
        Notify();
    }
}

void MainWindow::SlotOpenFile(){
    QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  ".",
                                                  tr("OBJ (*.obj)"));

}
} // namespace s21
