#include "include/controller.h"

#include <stdexcept>

namespace s21 {

Controller::Controller(BaseFileReader &file_reader_,
                       SceneDrawerBase &scene_drawer_, MySettings &settings_)
    : file_reader(file_reader_),
      scene_drawer(scene_drawer_),
      settings(settings_) {}

SceneParameters Controller::GetSettings() { return settings.GetSettings(); }

void Controller::UpdateSettings(const SceneParameters &scene_params) {
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

void Controller::SetParentForSceneDraw(QWidget *parent) {
  scene_drawer.SetParentOpenGL(parent);
}

void Controller::UpdateSceneDraw() { scene_drawer.UpdateScene(); }

void Controller::SetScene() {
  scene_drawer.SetScene(&scene);
  scene_drawer.UpdateScene();
}

void Controller::SetParamsScene(SceneParameters *params_scene) {
  scene_drawer.SetParamsScene(params_scene);
  scene_drawer.UpdateScene();
}

QImage Controller::GetFrameBuffer() { return scene_drawer.GetFrameBuffer(); }

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

// void MainWindow::StartMakingGif() {
//   ShowMessage(QString("Идет запись GIF"), QColor(39, 174, 96), 0);
//   gif_time_left = gif_time;
//   QString uniq_name =
//       QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-z");
//   gif_file_path = QString("%1/video_%2.gif").arg(gif_dir).arg(uniq_name);
//   gif_.InitializeGenerator(gif_file_path.toStdString(), gif_width,
//   gif_height,
//                            10, 500);
//   CreateFrameToGif();
// }

// void MainWindow::CreateFrameToGif() {
//   if (gif_.Finished()) {
//     ui->buttonCreateGif->setEnabled(true);
//     ShowMessage(QString("Создана GIF: %1").arg(gif_file_path),
//                 QColor(50, 205, 50), 5000);
//     return;
//   }
//   gif_.AddFrame(
//       controller.GetFrameBuffer().scaled(gif_width, gif_height).bits());
//   QTimer::singleShot(gif_delay, this, SLOT(CreateFrameToGif()));
// }

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

int Controller::GetGifDelay() { gif_generator.GetDelay(); }

}  // namespace s21
