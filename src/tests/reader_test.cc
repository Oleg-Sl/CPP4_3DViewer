#include <gtest/gtest.h>

#include "../model/filereader.h"
namespace s21 {

TEST(OBJReader, CorrectObjFile) {
  OBJReader reader;
  Scene scene = reader.ReadScene(
      "/home/alexander/Desktop/school/CPP4_3DViewer_v2.0-1/src/obj_examples/"
      "cube.obj");
  std::cout << std::endl;
  for (auto i : scene.GetFigures()) {
    i.PrintEdges();
  }
}

}  // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}