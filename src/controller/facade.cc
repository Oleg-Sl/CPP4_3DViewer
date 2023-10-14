#include "include/facade.h"


namespace s21 {

Facade::Facade(BaseFileReader& file_reader, SceneDrawerBase& scene_drawer) : file_reader(file_reader), scene_drawer(scene_drawer) {
}

void Facade::DrawScene(SceneParameters *scene_params) {
    // scene_drawer.DrawScene(&scene);
    scene_drawer.SetParamsScene(scene_params);
}

void Facade::LoadScene(const std::string& path) {
    scene = file_reader.ReadScene(path, params);
    scene_drawer.DrawScene(&scene);
}

void Facade::SetParentForSceneDraw(QWidget *parent) {
    scene_drawer.SetParentOpenGL(parent);
}

void Facade::MoveScene(float x, float y, float z) {
    scene.TransformFigures(TransformMatrixBuilder::CreateMoveMatrix(x,y,z));
}

void Facade::RotateScene(float x, float y, float z) {
    scene.TransformFigures(TransformMatrixBuilder::CreateRotationMatrix(x,y,z));
}

void Facade::ScaleScene(float x, float y, float z) {
    scene.TransformFigures(TransformMatrixBuilder::CreateScaleMatrix(x,y,z));
}

} // namespace s21
