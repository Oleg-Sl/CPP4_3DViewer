#include "include/controller.h"

#include <stdexcept>

namespace s21 {

Controller::Controller(BaseFileReader &file_reader_,
                       SceneDrawerBase &scene_drawer_, MySettings &settings_)
    : file_reader(file_reader_),
      scene_drawer(scene_drawer_),
      settings(settings_) {}

SceneParameters Controller::GetSettings() const { return settings.GetSettings(); }

void Controller::UpdateSettings(const SceneParameters &scene_params) const {
  return settings.UpdateSettings(scene_params);
}

OperationResult Controller::LoadScene(const QString &path) {
  try {
    scene = file_reader.ReadScene(path.toStdString());
  } catch (const std::exception &e) {
    return {e.what(), false};
  }
  SetScene();

  return {"", true};
}

void Controller::SetParentForSceneDraw(QWidget *parent) const {
  scene_drawer.SetParentOpenGL(parent);
}

void Controller::UpdateSceneDraw() const { scene_drawer.UpdateScene(); }

void Controller::SetScene() {
  scene_drawer.SetScene(&scene);
  scene_drawer.UpdateScene();
}

void Controller::SetParamsScene(SceneParameters *params_scene) const {
  scene_drawer.SetParamsScene(params_scene);
  scene_drawer.UpdateScene();
}

QImage Controller::GetFrameBuffer() const { return scene_drawer.GetFrameBuffer(); }

size_t Controller::GetCountVertices() const {
  return scene.GetCountVertices();
}

size_t Controller::GetCountEdges() const {
  return scene.GetCountEdges();
}

void Controller::MoveScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateMoveMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Controller::RotateScene(float x, float y, float z) {
  scene.TransformVertices(
      TransformMatrixBuilder::CreateRotationMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Controller::ScaleScene(float x, float y, float z) {
  scene.TransformVertices(TransformMatrixBuilder::CreateScaleMatrix(x, y, z));
  scene_drawer.UpdateScene();
}

void Controller::CreateGif(const std::string &filename, int gif_width,
                           int gif_height, int fps, int duration) {
  gif_generator.InitializeGenerator(filename, gif_width, gif_height, fps,
                                    duration);
}

bool Controller::AddGifFrame() {
  gif_generator.AddFrame(
      GetFrameBuffer()
          .scaled(gif_generator.GetWidth(), gif_generator.GetHeight())
          .bits());

  return gif_generator.GetFinished();
}

int Controller::GetGifDelay() const { gif_generator.GetDelay(); }

}  // namespace s21
