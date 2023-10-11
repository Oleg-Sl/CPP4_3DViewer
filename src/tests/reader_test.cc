#include <gtest/gtest.h>

#include <vector>

#include "../model/include/objreader.h"

namespace s21 {

TEST(OBJFileReader, CorrectObjFile) {
  std::vector<Vertex> vectrices = {Vertex({0.5, 0.5, 0.5}),
                                   Vertex({-0.5, 0.5, 0.5}),
                                   Vertex({-0.5, -0.5, 0.5})};

  std::vector<std::vector<Vertex>> figures = {
      {vectrices.at(0), vectrices.at(1), vectrices.at(2)},
      {vectrices.at(1), vectrices.at(0), vectrices.at(2)},
      {vectrices.at(2), vectrices.at(0), vectrices.at(1)}};

  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/correct_test.obj", {-0.5, 0.5, 0, 0});
  std::vector<Figure> scene_figures = scene.GetFigures();

  for (size_t i = 0; i < scene_figures.size(); ++i) {
    Figure curr_figure = scene_figures[i];
    for (size_t j = 0; j < curr_figure.GetVertices().size(); ++j) {
      ASSERT_EQ(curr_figure.GetVertices().at(j) == figures.at(i).at(j), true);
    }
  }
}

TEST(OBJFileReader, IncorrectFilePath) {
  OBJReader reader;

  ASSERT_THROW(reader.ReadScene("obj_examples/incorrect.obj", {}),
               std::runtime_error);
}

TEST(OBJFileReader, FileWithoutFaces) {
  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/without_faces.obj", {});

  ASSERT_EQ(scene.GetFigures().empty(), true);
}

TEST(OBJFileReaderThrow, IncorrectFaceIndex) {
  OBJReader reader;

  ASSERT_THROW(reader.ReadScene("obj_examples/incorrect_face_index.obj", {}),
               std::invalid_argument);
}

}  // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}