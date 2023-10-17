#include "include/objreader.h"

#include <fstream>
#include <iostream>

namespace s21 {

void OBJReader::ReadCoord(std::stringstream &tokens,
                          std::vector<float> &vertices) {
  float x, y, z;
  tokens >> x >> y >> z;
  vertices.push_back(x);
  vertices.push_back(y);
  vertices.push_back(z);
}

std::vector<size_t> OBJReader::ReadFace(std::stringstream &tokens,
                                        size_t count_vertices) {
  int vertex_index;
  std::string line;
  std::vector<size_t> edges;
  std::vector<size_t> added_vertices;

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
      vertex_index = count_vertices + vertex_index;
    } else {
      vertex_index -= 1;
    }
    if (vertex_index < 0 || vertex_index >= static_cast<int>(count_vertices)) {
      throw std::invalid_argument("Invalid face index: " +
                                  std::to_string(vertex_index));
    }
    added_vertices.push_back(vertex_index);
  }

  for (size_t i = 0; i < added_vertices.size(); ++i) {
    size_t start = i;
    size_t end = i + 1 == added_vertices.size() ? 0 : i + 1;

    edges.push_back(added_vertices[start]);
    edges.push_back(added_vertices[end]);
  }

  return edges;
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
  std::vector<float> vertices;
  std::vector<size_t> edges;
  std::ifstream obj_file(path);

  if (obj_file.is_open()) {
    std::string curr_line;

    while (std::getline(obj_file, curr_line)) {
      std::stringstream tokens(curr_line);
      std::string curr_token;
      tokens >> curr_token;

      if (curr_token == kVertexToken) {
        ReadCoord(tokens, vertices);
        // CalculateNormalizationParams(vertex, scene);
      } else if (curr_token == kFaceToken) {
        std::vector<size_t> temp = ReadFace(tokens, vertices.size());
        edges.insert(edges.end(), temp.begin(), temp.end());
      }
    }

    obj_file.close();
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }

  scene.SetVertices(vertices);
  scene.SetEdges(edges);

  return scene;
}

} // namespace s21
