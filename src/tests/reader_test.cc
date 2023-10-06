#include <gtest/gtest.h>

#include <vector>

#include "../model/filereader.h"

namespace s21 {

TEST(OBJReader, CorrectObjFile) {
  std::vector<Vertex> cube_vectrices = {
      Vertex({0.5, 0.5, 0.5}),   Vertex({-0.5, 0.5, 0.5}),
      Vertex({-0.5, 0.5, 0.5}),  Vertex({-0.5, -0.5, 0.5}),
      Vertex({0.5, -0.5, 0.5}),  Vertex({0.5, 0.5, -0.5}),
      Vertex({-0.5, 0.5, -0.5}), Vertex({-0.5, -0.5, -0.5}),
      Vertex({0.5, -0.5, -0.5})};

  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/cube.obj");

  for (Figure figure : scene.GetFigures()) {
    for (size_t i = 0; i < figure.GetVertices().size(); ++i) {
      figure.GetVertices().at(i) == cube_vectrices.at(i);
    }
  }
}

}  // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}