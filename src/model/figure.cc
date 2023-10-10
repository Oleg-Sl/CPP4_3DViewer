#include "include/figure.h"

#include <iostream>

namespace s21 {

Figure::Figure() {}

Figure::Figure(std::initializer_list<Point3D> points) {
  for (auto point : points) {
    vertices_.push_back(point);
  }
}

std::vector<Vertex> &Figure::GetVertices() { return vertices_; }

std::vector<Edge> &Figure::GetEdges() { return edges_; }

void Figure::Transform(const TransformMatrix &matrix) {
  for (auto &vertex : vertices_) {
    vertex.Transform(matrix);
  }
}

void Figure::PrintEdges() const {
  for (const Edge &edge : edges_) {
    std::cout << "A: " << edge.GetBegin().GetPosition().x << " "
              << edge.GetBegin().GetPosition().y << " "
              << edge.GetBegin().GetPosition().z << std::endl;

    std::cout << "B: " << edge.GetEnd().GetPosition().x << " "
              << edge.GetEnd().GetPosition().y << " "
              << edge.GetEnd().GetPosition().z << std::endl;
  }
}

void Figure::AddVertex(Vertex vertex) { vertices_.push_back(vertex); }

void Figure::AddEdge(size_t vertex1_index, size_t vertex2_index) {
  if (vertex1_index < vertices_.size() && vertex2_index < vertices_.size()) {
    edges_.emplace_back(vertices_.at(vertex1_index),
                        vertices_.at(vertex2_index));
  } else {
    throw std::invalid_argument(
        "Invalid edge indices: " + std::to_string(vertex1_index) + " " +
        std::to_string(vertex2_index));
  }
}

}  // namespace s21