#include "vertex.h"

namespace s21 {

Vertex::Vertex(Point3D point) : position(point) {}

const Point3D& Vertex::GetPosition() const { return position; }

void Vertex::Transform(const TransformMatrix& matrix) {
  position = matrix.TransformPoint(position);
}

bool Vertex::operator==(const Vertex& other) {
  return GetPosition().x == other.GetPosition().x &&
         GetPosition().y == other.GetPosition().y &&
         GetPosition().z == other.GetPosition().z;
}

}  // namespace s21