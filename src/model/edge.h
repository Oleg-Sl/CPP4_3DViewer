#ifndef _3DVIEWER_MODEL_EDGE_H_
#define _3DVIEWER_MODEL_EDGE_H_

#include "vertex.h"


class Edge {
public:
    Vertex& GetBegin() const;
    Vertex& GetEnd() const;

private:
    Vertex& begin;
    Vertex& end;
};

#endif  // _3DVIEWER_MODEL_EDGE_H_
