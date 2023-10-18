#include "include/facade.h"

namespace s21 {

Facade::Facade(BaseFileReader& file_reader_, SceneDrawerBase& scene_drawer_,
               MySettings& settings_)
    : file_reader(file_reader_),
      scene_drawer(scene_drawer_),
      settings(settings_) {}

SceneParameters Facade::GetSettings() { return settings.GetSettings(); }

void Facade::UpdateSettings(const SceneParameters& scene_params) {
  return settings.UpdateSettings(scene_params);
}

void Facade::LoadScene(const QString& path) {
  scene = file_reader.ReadScene(path.toStdString());
  SetScene();
}

void Facade::SetParentForSceneDraw(QWidget* parent) {
  scene_drawer.SetParentOpenGL(parent);
}

void Facade::UpdateSceneDraw() { scene_drawer.UpdateScene(); }

void Facade::SetScene() {
  scene_drawer.SetScene(&scene);
  scene_drawer.UpdateScene();
}

void Facade::SetParamsScene(SceneParameters* params_scene) {
  scene_drawer.SetParamsScene(params_scene);
  scene_drawer.UpdateScene();
}

QImage Facade::GetFrameBuffer() { return scene_drawer.GetFrameBuffer(); }

void Facade::MoveScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateMoveMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Facade::RotateScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateRotationMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Facade::ScaleScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateScaleMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

}  // namespace s21
