#ifndef _3DVIEWER_MODEL_FIGURE_H_
#define _3DVIEWER_MODEL_FIGURE_H_

#include "scene_object.h"
#include "transform_matrix.h"
#include "vertex.h"
#include "edge.h"

#include <vector>


class Figure : public SceneObject{
public:
    std::vector<Vertex>& GetVertices();
    std::vector<Edge>& GetEdges();
    void Transform(const TransformMatrix&);

private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};

#endif  // _3DVIEWER_MODEL_FIGURE_H_
