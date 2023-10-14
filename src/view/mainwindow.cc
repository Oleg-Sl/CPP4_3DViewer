#include "include/mainwindow.h"

#include "ui_mainwindow.h"


namespace s21 {

MainWindow::MainWindow(Facade& ctrl, QWidget *parent) : QMainWindow(parent), controller(ctrl), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    controller.SetParentForSceneDraw(ui->widgetOpenGL);
    controller.LoadScene("/home/oleg/school21/CPP4_3DViewer_v2.0-1/src/obj_examples/Fantasy Dragon.obj");
//    controller.LoadScene("/Users/julissam/projects/CPP4_3DViewer_v2.0-1/src/obj_examples/cube.obj");

    connect(ui->typeProjection,  SIGNAL(activated(int)),    this, SLOT(SlotChangeTypeProjection(int)));
    connect(ui->backgroundColor, SIGNAL(clicked()),         this, SLOT(SlotChangeBackground()));
    connect(ui->lineType,        SIGNAL(activated(int)),    this, SLOT(SlotChangeEdgeType(int)));
    connect(ui->lineWidth,       SIGNAL(valueChanged(int)), this, SLOT(SlotChangeEdgeWidth(int)));
    connect(ui->lineColor,       SIGNAL(clicked()),         this, SLOT(SlotChangeEdgeColor()));
    connect(ui->vertexType,      SIGNAL(activated(int)),    this, SLOT(SlotChangeVertexType(int)));
    connect(ui->vertexSize,      SIGNAL(valueChanged(int)), this, SLOT(SlotChangeVertexSize(int)));
    connect(ui->vertexColor,     SIGNAL(clicked()),         this, SLOT(SlotChangeVertexColor()));

    connect(ui->moveX,          SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectX(int)));
    connect(ui->moveY,          SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectY(int)));
    connect(ui->moveZ,          SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectZ(int)));
    connect(ui->sliderMoveX,    SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectX(int)));
    connect(ui->sliderMoveY,    SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectY(int)));
    connect(ui->sliderMoveZ,    SIGNAL(valueChanged(int)), this, SLOT(SlotMoveObjectZ(int)));

    connect(ui->rotateX,        SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectX(int)));
    connect(ui->rotateY,        SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectY(int)));
    connect(ui->rotateZ,        SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectZ(int)));
    connect(ui->sliderRotateX,  SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectX(int)));
    connect(ui->sliderRotateY,  SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectY(int)));
    connect(ui->sliderRotateZ,  SIGNAL(valueChanged(int)), this, SLOT(SlotRotateObjectZ(int)));

    connect(ui->scale,          SIGNAL(valueChanged(int)), this, SLOT(SlotScaleObjectXYZ(int)));
    connect(ui->sliderScale,    SIGNAL(valueChanged(int)), this, SLOT(SlotScaleObjectXYZ(int)));

}

MainWindow::~MainWindow() {
    controller.SetParentForSceneDraw(nullptr);
    delete ui;
}

void MainWindow::Notify() {
    controller.DrawScene(&scene_params);
}

void MainWindow::SlotMoveObjectX(int offset) {
    if (offset == previous_offsets.x) {
        return;
    }
    controller.MoveScene(offset - previous_offsets.x, 0, 0);
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
    controller.RotateScene(angle_deg * M_PI / 180 - previous_rotation.x, 0, 0);
    previous_rotation.x = angle_deg * M_PI / 180;
    ui->sliderRotateX->setSliderPosition(angle_deg);
    ui->rotateX->setValue(angle_deg);
}

void MainWindow::SlotRotateObjectY(int angle_deg) {
    if (angle_deg == previous_rotation.y) {
        return;
    }
    controller.RotateScene(0, angle_deg * M_PI / 180 - previous_rotation.y, 0);
    previous_rotation.y = angle_deg * M_PI / 180;
    ui->sliderRotateY->setSliderPosition(angle_deg);
    ui->rotateY->setValue(angle_deg);
}

void MainWindow::SlotRotateObjectZ(int angle_deg) {
    if (angle_deg == previous_rotation.z) {
        return;
    }
    controller.RotateScene(0, 0, angle_deg * M_PI / 180 - previous_rotation.z);
    previous_rotation.z = angle_deg * M_PI / 180;
    ui->sliderRotateZ->setSliderPosition(angle_deg);
    ui->rotateZ->setValue(angle_deg);
}

void MainWindow::SlotScaleObjectXYZ(int scale) {

    controller.ScaleScene(scale / previous_scales.x, scale / previous_scales.y, scale / previous_scales.z);

    previous_scales.x = scale;
    previous_scales.y = scale;
    previous_scales.z = scale;
    ui->sliderScale->setSliderPosition(scale);
    ui->scale->setValue(scale);
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


} // namespace s21
