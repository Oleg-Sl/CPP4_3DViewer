#include "include/objreader.h"

#include <fstream>
#include <iostream>

namespace s21 {

Vertex OBJReader::ReadVertex(std::stringstream& tokens) {
  float x, y, z;
  tokens >> x >> y >> z;
  return Vertex({x, y, z});
}

Figure OBJReader::ReadFace(std::stringstream& tokens,
                           const std::vector<Vertex>& vertices) {
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

void OBJReader::NormalizationScene(Scene& scene,
                                   const NormalizationParameters& params) {
  Bounds scene_bounds = scene.GetBounds();

  float overall_diff_x =
      scene_bounds.max_vertex_x_value - scene_bounds.min_vertex_x_value;
  float overall_diff_y =
      scene_bounds.max_vertex_y_value - scene_bounds.min_vertex_y_value;
  float overall_diff_z =
      scene_bounds.max_vertex_z_value - scene_bounds.min_vertex_z_value;

  float overall_diff =
      std::max(overall_diff_x, std::max(overall_diff_y, overall_diff_z));

  if (overall_diff != 0) {
    float scale = (params.max - params.min) / overall_diff;

    for (Figure& figure : scene.GetFigures()) {
      for (Vertex& vertex : figure.GetVertices()) {
        float new_x_position =
            (vertex.GetPosition().x - scene_bounds.min_vertex_x_value) * scale +
            params.min;
        float new_y_position =
            (vertex.GetPosition().y - scene_bounds.min_vertex_y_value) * scale +
            params.min;
        float new_z_position =
            (vertex.GetPosition().z - scene_bounds.min_vertex_z_value) * scale +
            params.min;
        vertex.SetPosition({new_x_position, new_y_position, new_z_position});
      }
    }
  }
}

void OBJReader::CalculateSceneBounds(Scene& scene, const Vertex& vertex) {
  Bounds scene_bounds = scene.GetBounds();

  scene_bounds.min_vertex_x_value =
      std::min(vertex.GetPosition().x, scene_bounds.min_vertex_x_value);
  scene_bounds.min_vertex_y_value =
      std::min(vertex.GetPosition().y, scene_bounds.min_vertex_y_value);
  scene_bounds.min_vertex_z_value =
      std::min(vertex.GetPosition().z, scene_bounds.min_vertex_z_value);

  scene_bounds.max_vertex_x_value =
      std::max(vertex.GetPosition().x, scene_bounds.max_vertex_x_value);
  scene_bounds.max_vertex_y_value =
      std::max(vertex.GetPosition().y, scene_bounds.max_vertex_y_value);
  scene_bounds.max_vertex_z_value =
      std::max(vertex.GetPosition().z, scene_bounds.max_vertex_z_value);

  scene.SetBounds(scene_bounds);
}

Scene OBJReader::ReadScene(const std::string& path,
                           const NormalizationParameters& params) {
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
        CalculateSceneBounds(scene, vertex);
      } else if (curr_token == kFaceToken) {
        Figure figure = ReadFace(tokens, vertices);
        scene.AddFigure(std::move(figure));
      }
    }

    obj_file.close();
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }

  NormalizationScene(scene, params);

  return scene;
}

}  // namespace s21
