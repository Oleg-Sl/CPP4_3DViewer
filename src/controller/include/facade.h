#ifndef _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
#define _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_

#include "../../model/include/scene.h"
#include "../../model/include/objreader.h"
#include "../../view/include/scenedrawer.h"


namespace s21 {

class Facade {

public:
  Facade(BaseFileReader& file_reader, SceneDrawer& scene_drawer) : file_reader(file_reader), scene_drawer(scene_drawer) {
  }

  void DrawScene(Scene scene) {
    scene_drawer.DrawScene(scene);
  }

  void SetParentForSceneDraw(QWidget *parent) {
    scene_drawer.SetParentOpenGL(parent);
  }

  void LoadScene(const std::string& path, const NormalizationParameters& params) {
  // scene = reader.ReadScene(
  //       "/Users/julissam/projects/CPP4_3DViewer_v2.0-1/src/obj_examples/cube.obj",
  //       {-0.5, 0.5});
  }

  // void MoveScene(float x, float y, float z) {
  // }

  // void RotateScene(float x, float y, float z) {
  // }

  // void ScaleScene(float x, float y, float z) {
  // }

private:
  BaseFileReader& file_reader;
  SceneDrawer& scene_drawer;
  // Scene& scene;

};

} // namespace s21

#endif // _3DVIEWER_CONTROLLER_INCLUDE_FACADE_H_
