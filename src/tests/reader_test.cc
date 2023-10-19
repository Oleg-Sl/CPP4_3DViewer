#include <gtest/gtest.h>

#include <vector>

#include "../model/include/objreader.h"

namespace s21 {

TEST(OBJFileReader, CorrectObjFile) {
  std::vector<float> vertices = {0.5, 0.5,  0.5,  -0.5, 0.5,
                                 0.5, -0.5, -0.5, 0.5};

  std::vector<int> edges = {0, 1, 1, 2, 2, 0, 1, 0, 0,
                            2, 2, 1, 2, 0, 0, 1, 1, 2};

  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/correct_test.obj");
  auto scene_vertices = scene.GetVertices();
  auto scene_edges = scene.GetEdges();

  ASSERT_EQ(vertices.size(), scene_vertices.size());
  ASSERT_EQ(edges.size(), scene_edges.size());

  for (size_t i = 0; i < vertices.size(); i++) {
    ASSERT_EQ(vertices[i], scene_vertices[i]);
  }

  for (size_t i = 0; i < edges.size(); i++) {
    ASSERT_EQ(edges[i], scene_edges[i]);
  }
}

TEST(OBJFileReader, IncorrectFilePath) {
  OBJReader reader;

  ASSERT_THROW(reader.ReadScene("obj_examples/incorrect.obj"),
               std::runtime_error);
}

TEST(OBJFileReader, FileWithoutFaces) {
  OBJReader reader;
  Scene scene = reader.ReadScene("obj_examples/without_faces.obj");

  ASSERT_EQ(scene.GetEdges().empty(), true);
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