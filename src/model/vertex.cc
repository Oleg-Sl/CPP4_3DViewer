#include "include/vertex.h"

namespace s21 {

Vertex::Vertex(Point3D point) : position_(point) {}

const Point3D& Vertex::GetPosition() const { return position_; }
void Vertex::SetPosition(Point3D new_position) { position_ = new_position; }

void Vertex::Transform(const TransformMatrix& matrix) {
  position_ = matrix.TransformPoint(position_);
}

bool Vertex::operator==(const Vertex& other) {
  return GetPosition().x == other.GetPosition().x &&
         GetPosition().y == other.GetPosition().y &&
         GetPosition().z == other.GetPosition().z;
}

}  // namespace s21