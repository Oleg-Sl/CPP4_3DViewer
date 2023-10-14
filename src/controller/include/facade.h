#ifndef _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
#define _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_

#include "../../model/include/scene.h"
#include "../../model/include/objreader.h"
#include "../../view/include/scenedrawer.h"
#include "../../model/include/transform_matrix_builder.h"

#include <QDebug>


namespace s21 {

class Facade {

public:
  Facade(BaseFileReader& file_reader, SceneDrawerBase& scene_drawer);

  void DrawScene(SceneParameters *scene_params);

  void LoadScene(const std::string& path);

  void SetParentForSceneDraw(QWidget *parent);

  void MoveScene(float x, float y, float z);

  void RotateScene(float x, float y, float z);

  void ScaleScene(float x, float y, float z);

private:
  BaseFileReader& file_reader;
  SceneDrawerBase& scene_drawer;
  Scene scene{};
  const NormalizationParameters params{0.5, 0.5, 0, 0};
};

} // namespace s21

#endif // _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
