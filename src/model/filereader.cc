#include "include/filereader.h"

#include <execution>
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
  int vertex_index;
  int vertex_counter = 0;
  while (tokens >> vertex_index) {
    vertex_counter++;

    if (vertex_index < 0) {
      vertex_index = vertices.size() + vertex_index;
    } else {
      vertex_index -= 1;
    }
    if (vertex_index < 0 || vertex_index > (int)vertices.size() - 1) {
      throw std::invalid_argument("Face index out of range");
    }

    figure.AddVertex(vertices[vertex_index]);
  }

  for (int i = 0; i < vertex_counter; ++i) {
    int start_index = i;
    int end_index = (i + 1) % vertex_counter;

    figure.AddEdge({figure.GetVertices().at(start_index),
                    figure.GetVertices().at(end_index)});
  }

  scene.AddFigure(std::move(figure));
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

} // namespace s21
