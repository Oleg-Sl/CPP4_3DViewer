#include "include/edge.h"

namespace s21 {

Edge::Edge(Vertex &begin_vetex, Vertex &end_vertex)
    : begin_(begin_vetex), end_(end_vertex) {}

Vertex &Edge::GetBegin() const { return begin_; }
Vertex &Edge::GetEnd() const { return end_; }

} // namespace s21