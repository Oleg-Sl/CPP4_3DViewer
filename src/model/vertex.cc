#include "vertex.h"

namespace s21 {

Vertex::Vertex(Point3D point) : position(point) {}

const Point3D& Vertex::GetPosition() const { return position; }

void Vertex::Transform(const TransformMatrix& matrix) {
  position = matrix.TransformPoint(position);
}

}  // namespace s21