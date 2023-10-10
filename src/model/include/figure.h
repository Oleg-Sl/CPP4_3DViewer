#ifndef _3DVIEWER_MODEL_FIGURE_H_
#define _3DVIEWER_MODEL_FIGURE_H_

#include <vector>

#include "edge.h"
#include "scene_object.h"
#include "transform_matrix.h"
#include "vertex.h"

namespace s21 {

class Figure : public SceneObject {
 public:
  Figure();
  Figure(std::initializer_list<Point3D> points);
  std::vector<Vertex> &GetVertices();
  std::vector<Edge> &GetEdges();
  void Transform(const TransformMatrix &);
  void AddEdge(size_t vertex1_index, size_t vertex2_index);
  void AddVertex(Vertex vertex);
  void PrintEdges() const;

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_FIGURE_H_
