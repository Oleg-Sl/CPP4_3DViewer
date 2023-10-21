#ifndef _3DVIEWER_CONTROLLER_INCLUDE_CONTROLLER_H_
#define _3DVIEWER_CONTROLLER_INCLUDE_CONTROLLER_H_

#include "../../model/include/gifgenerator.h"
#include "../../model/include/objreaderfast.h"
#include "../../model/include/scene.h"
#include "../../model/include/settings.h"
#include "../../model/include/transform_matrix_builder.h"
#include "../../view/include/scenedrawer.h"
#include "operationresult.h"

namespace s21 {

class Controller {
 public:
  Controller(BaseFileReader &, SceneDrawerBase &, MySettings &);

  SceneParameters GetSettings();
  void UpdateSettings(const SceneParameters &);

  OperationResult LoadScene(const QString &);

  void UpdateSceneDraw();
  void SetScene();
  void SetParamsScene(SceneParameters *);
  void SetParentForSceneDraw(QWidget *);
  QImage GetFrameBuffer();

  void MoveScene(float x, float y, float z);
  void RotateScene(float x, float y, float z);
  void ScaleScene(float x, float y, float z);

  void CreateGif(const std::string &filename, int gif_width, int gif_height,
                 int fps, int duration);
  bool AddGifFrame();
  int GetGifDelay();

 private:
  BaseFileReader &file_reader;
  SceneDrawerBase &scene_drawer;
  MySettings &settings;
  Scene scene{};
  GifGenerator gif_generator;
};

}  // namespace s21

#endif  // _3DVIEWER_CONTROLLER_INCLUDE_CONTROLLER_H_
