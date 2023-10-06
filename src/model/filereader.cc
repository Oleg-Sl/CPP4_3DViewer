#include "filereader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace s21 {

const std::string kVertexToken = "v";
const std::string kFaceToken = "f";

Scene OBJReader::ReadScene(std::string path) {
  Scene scene;

  std::vector<Vertex> vertices;

  std::ifstream obj_file;
  obj_file.open(path);

  if (obj_file.is_open()) {
    std::string curr_str;

    while (std::getline(obj_file, curr_str)) {
      std::stringstream ss(curr_str);

      std::string curr_lexem;
      ss >> curr_lexem;

      if (curr_lexem == kVertexToken) {
        float x, y, z;
        ss >> x >> y >> z;
        vertices.push_back(Vertex({x, y, z}));
      } else if (curr_lexem == kFaceToken) {
        Figure figure;
        std::vector<int> vertex_indices;
        int vertex_index;
        while (ss >> vertex_index) {
          vertex_indices.push_back(vertex_index - 1);
        }

        for (size_t i = 0; i < vertex_indices.size(); ++i) {
          int start_index = vertex_indices[i];
          int end_index = vertex_indices[(i + 1) % vertex_indices.size()];
          figure.AddEdge(Edge(vertices[start_index], vertices[end_index]));
        }

        scene.AddFigure(figure);
      }
    }

    obj_file.close();
  } else {
    std::cout << "No file";
  }

  // for (auto i : scene.GetFigures()) {
  //   i.PrintEdges();
  // }

  return scene;
}

}  // namespace s21
