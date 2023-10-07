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
void Figure::AddEdge(Edge edge) { edges_.push_back(edge); }

} // namespace s21