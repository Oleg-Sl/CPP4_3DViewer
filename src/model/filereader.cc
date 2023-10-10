#include "include/filereader.h"

#include <fstream>
#include <iostream>

namespace s21 {

void OBJReader::ReadVertex(std::stringstream& tokens,
                           std::vector<Vertex>& vertices) {
  float x, y, z;
  tokens >> x >> y >> z;
  vertices.push_back(Vertex({x, y, z}));
}

void OBJReader::ReadFace(std::stringstream& tokens,
                         const std::vector<Vertex>& vertices, Scene& scene) {
  Figure figure;
  int vertex_index;
  std::string line;

  while (tokens >> line) {
    std::string token;

    size_t slash_pos = line.find("//");

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
    if (vertex_index < 0 || vertex_index >= static_cast<int>(vertices.size())) {
      throw std::invalid_argument("Invalid face index: " +
                                  std::to_string(vertex_index));
    }

    figure.AddVertex(vertices[vertex_index]);
  }

  for (size_t i = 0; i < figure.GetVertices().size(); ++i) {
    size_t end = i + 1 == figure.GetVertices().size() ? 0 : i + 1;
    figure.AddEdge(i, end);
  }

  scene.AddFigure(std::move(figure));
}

Scene OBJReader::ReadScene(const std::string& path) {
  Scene scene;
  std::vector<Vertex> vertices;
  std::ifstream obj_file(path);

  if (obj_file.is_open()) {
    std::string curr_line;

    while (std::getline(obj_file, curr_line)) {
      std::stringstream tokens(curr_line);
      std::string curr_token;
      tokens >> curr_token;

      if (curr_token == kVertexToken) {
        ReadVertex(tokens, vertices);
      } else if (curr_token == kFaceToken) {
        ReadFace(tokens, vertices, scene);
      }
    }

    obj_file.close();
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }

  return scene;
}

}  // namespace s21
