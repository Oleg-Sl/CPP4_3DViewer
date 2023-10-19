#include "include/controller.h"

namespace s21 {

Controller::Controller(BaseFileReader& file_reader_, SceneDrawerBase& scene_drawer_,
               MySettings& settings_)
    : file_reader(file_reader_),
      scene_drawer(scene_drawer_),
      settings(settings_) {}

SceneParameters Controller::GetSettings() { return settings.GetSettings(); }

void Controller::UpdateSettings(const SceneParameters& scene_params) {
  return settings.UpdateSettings(scene_params);
}

void Controller::LoadScene(const QString& path) {
  scene = file_reader.ReadScene(path.toStdString());
  SetScene();
}

void Controller::SetParentForSceneDraw(QWidget* parent) {
  scene_drawer.SetParentOpenGL(parent);
}

void Controller::UpdateSceneDraw() { scene_drawer.UpdateScene(); }

void Controller::SetScene() {
  scene_drawer.SetScene(&scene);
  scene_drawer.UpdateScene();
}

void Controller::SetParamsScene(SceneParameters* params_scene) {
  scene_drawer.SetParamsScene(params_scene);
  scene_drawer.UpdateScene();
}

QImage Controller::GetFrameBuffer() { return scene_drawer.GetFrameBuffer(); }

void Controller::MoveScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateMoveMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Controller::RotateScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateRotationMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Controller::ScaleScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateScaleMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

}  // namespace s21
