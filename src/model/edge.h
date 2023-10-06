#ifndef _3DVIEWER_MODEL_EDGE_H_
#define _3DVIEWER_MODEL_EDGE_H_

#include "vertex.h"

namespace s21 {

class Edge {
 public:
  Edge(const Vertex &begin_vetex, const Vertex &end_vertex);
  Vertex GetBegin() const;
  Vertex GetEnd() const;

 private:
  Vertex begin;
  Vertex end;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_EDGE_H_
