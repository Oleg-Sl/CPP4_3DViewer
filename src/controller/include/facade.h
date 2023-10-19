#ifndef _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
#define _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_

#include "../../model/include/scene.h"
#include "../../model/include/objreader.h"
#include "../../view/include/scenedrawer.h"
#include "../../model/include/transform_matrix_builder.h"
#include "../../model/include/settings.h"

#include <QDebug>


namespace s21 {

class Facade {

public:
  Facade(BaseFileReader&, SceneDrawerBase&, MySettings&);

  SceneParameters GetSettings();
  void UpdateSettings(const SceneParameters&);

  void LoadScene(const QString&);

  void UpdateSceneDraw();
  void SetScene();
  void SetParamsScene(SceneParameters *);
  void SetParentForSceneDraw(QWidget *);
  QImage GetFrameBuffer();

  void MoveScene(float x, float y, float z);
  void RotateScene(float x, float y, float z);
  void ScaleScene(float x, float y, float z);

private:
  BaseFileReader& file_reader;
  SceneDrawerBase& scene_drawer;
  MySettings& settings;
  Scene scene{};
};

} // namespace s21

#endif // _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
