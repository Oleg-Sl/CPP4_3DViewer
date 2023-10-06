#include "edge.h"

namespace s21 {

Edge::Edge(Vertex &begin_vetex, Vertex &end_vertex)
    : begin(begin_vetex), end(end_vertex) {}

Vertex Edge::GetBegin() const { return begin; }
Vertex Edge::GetEnd() const { return end; }

}  // namespace s21