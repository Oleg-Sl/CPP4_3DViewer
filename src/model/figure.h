#ifndef _3DVIEWER_MODEL_FIGURE_H_
#define _3DVIEWER_MODEL_FIGURE_H_

#include "scene_object.h"
#include "transform_matrix.h"
#include "vertex.h"
#include "edge.h"

#include <vector>


class Figure : public SceneObject{
public:
    // template<typename... Args>
    // void Figure(Args&&... points) {
    //     (figures.push_back(std::forward<Args>(points)), ...);
    // }
    Figure(std::initializer_list<Point3D> points) {
        for (auto point : points) {
            vertices.push_back(point);
        }
    }
    std::vector<Vertex>& GetVertices();
    std::vector<Edge>& GetEdges();
    void Transform(const TransformMatrix&);

private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};

#endif  // _3DVIEWER_MODEL_FIGURE_H_
