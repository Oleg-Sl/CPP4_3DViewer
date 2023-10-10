#include "include/filereader.h"

#include <execution>
#include <fstream>
#include <iostream>

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
  std::string line;

  while (tokens >> line) {
    std::string token;

    size_t slash_pos = line.find('/');

    if (slash_pos != std::string::npos) {
      token = line.substr(0, slash_pos);
    } else {
      token = line;
    }

    vertex_index = std::stoi(token);

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

  for (auto cur_vertex = figure.GetVertices().begin();
       cur_vertex != figure.GetVertices().end(); ++cur_vertex) {
    figure.AddEdge({*cur_vertex, *(cur_vertex + 1)});
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

}  // namespace s21
