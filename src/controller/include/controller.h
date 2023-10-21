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

  size_t GetCountVertices();
  size_t GetCountEdges();

  void MoveScene(float, float, float);
  void RotateScene(float, float, float);
  void ScaleScene(float, float, float);

  void CreateGif(const std::string &, int, int, int, int);
  bool AddGifFrame();
  int GetGifDelay();

 private:
  BaseFileReader &file_reader_;
  SceneDrawerBase &scene_drawer_;
  MySettings &settings_;
  Scene scene_{};
  GifGenerator gif_generator_{};
};

}  // namespace s21

#endif  // _3DVIEWER_CONTROLLER_INCLUDE_CONTROLLER_H_
