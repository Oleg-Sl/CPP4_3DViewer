#include "figure.h"


std::vector<Vertex>& Figure::GetVertices() {
    return vertices;
}

std::vector<Edge>& Figure::GetEdges() {
    return edges;
}

void Figure::Transform(const TransformMatrix& matrix) {
    for (auto vertex : vertices) {
        vertex.Transform(matrix);
    }
}
