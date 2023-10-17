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
  Scene scene = reader.ReadScene("obj_examples/correct_test.obj");
  for (auto i : scene.GetEdges()) {
    std::cout << i << std::endl;
  }

  for (auto i : scene.GetVertices()) {
    std::cout << i << std::endl;
  }
}

// TEST(OBJFileReader, IncorrectFilePath) {
//   OBJReader reader;

//   ASSERT_THROW(reader.ReadScene("obj_examples/incorrect.obj"),
//                std::runtime_error);
// }

// TEST(OBJFileReader, FileWithoutFaces) {
//   OBJReader reader;
//   Scene scene = reader.ReadScene("obj_examples/without_faces.obj");

//   ASSERT_EQ(scene.GetFigures().empty(), true);
// }

// TEST(OBJFileReaderThrow, IncorrectFaceIndex) {
//   OBJReader reader;

//   ASSERT_THROW(reader.ReadScene("obj_examples/incorrect_face_index.obj"),
//                std::invalid_argument);
// }

} // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}