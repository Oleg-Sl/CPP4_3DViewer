#include "include/objreader.h"

#include <fstream>
#include <iostream>

namespace s21 {

Vertex OBJReader::ReadVertex(std::stringstream &tokens) {
  float x, y, z;
  tokens >> x >> y >> z;
  return Vertex({x, y, z});
}

Figure OBJReader::ReadFace(std::stringstream &tokens,
                           const std::vector<Vertex> &vertices) {
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

  return figure;
}

void OBJReader::CalculateNormalizationParams(const Vertex &vertex,
                                             Scene &scene) {
  NormalizationParameters params = scene.GetNormalizationParams();

  params.min = std::min(vertex.GetPosition().x, params.min);
  params.min = std::min(vertex.GetPosition().y, params.min);
  params.min = std::min(vertex.GetPosition().z, params.min);

  params.max = std::max(vertex.GetPosition().x, params.max);
  params.max = std::max(vertex.GetPosition().y, params.max);
  params.max = std::max(vertex.GetPosition().z, params.max);

  scene.SetNormalizationParams(params);
}

Scene OBJReader::ReadScene(const std::string &path) {
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
        Vertex vertex = ReadVertex(tokens);
        vertices.push_back(vertex);
        CalculateNormalizationParams(vertex, scene);
      } else if (curr_token == kFaceToken) {
        Figure figure = ReadFace(tokens, vertices);
        scene.AddFigure(std::move(figure));
      }
    }

    obj_file.close();
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }

  return scene;
}

} // namespace s21
