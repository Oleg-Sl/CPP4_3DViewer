#include <gtest/gtest.h>

#include <vector>

#include "../model/include/filereader.h"

namespace s21 {

TEST(OBJFileReader, CorrectObjFile) {
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

TEST(OBJFileReader, IncorrectFilePath) {
  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/incorrect.obj");

  ASSERT_EQ(scene.GetFigures().empty(), true);
}

TEST(OBJFileReader, FileWithoutFaces) {
  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/without_faces.obj");

  ASSERT_EQ(scene.GetFigures().empty(), true);
}

TEST(OBJFileReaderThrow, IncorrectFaceIndex) {
  OBJReader reader;

  ASSERT_THROW(reader.ReadScene("obj_examples/incorrect_face_index.obj"),
               std::invalid_argument);
}

} // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}