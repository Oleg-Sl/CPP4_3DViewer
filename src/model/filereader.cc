#include "include/filereader.h"

#include <fstream>

namespace s21 {

void OBJReader::VertexHandler(std::stringstream &tokens,
                              std::vector<Vertex> &vertices) {
  float x, y, z;
  tokens >> x >> y >> z;
  vertices.push_back(Vertex({x, y, z}));
}

void OBJReader::FaceHandler(std::stringstream &tokens,
                            const std::vector<Vertex> &vertices, Scene &scene) {
  Figure figure;
  std::vector<int> vertex_indices;
  int vertex_index;
  while (tokens >> vertex_index) {
    if (vertex_index < 0) {
      vertex_index = vertices.size() + vertex_index;
    } else {
      vertex_index -= 1;
    }
    vertex_indices.push_back(vertex_index);
  }

  for (size_t i = 0; i < vertex_indices.size(); ++i) {
    int start_index = vertex_indices[i];
    int end_index = vertex_indices[(i + 1) % vertex_indices.size()];
    figure.AddEdge(Edge(vertices[start_index], vertices[end_index]));
  }

  scene.AddFigure(figure);
}

Scene OBJReader::ReadScene(std::string path) {
  Scene scene;
  std::vector<Vertex> vertices;
  std::ifstream obj_file;

  obj_file.open(path);

  if (obj_file.is_open()) {
    std::string curr_str;

    while (std::getline(obj_file, curr_str)) {
      std::stringstream tokens(curr_str);

      std::string curr_lexem;
      tokens >> curr_lexem;

      if (curr_lexem == kVertexToken) {
        VertexHandler(tokens, vertices);
      } else if (curr_lexem == kFaceToken) {
        FaceHandler(tokens, vertices, scene);
      }
    }

    obj_file.close();
  }

  return scene;
}

}  // namespace s21
