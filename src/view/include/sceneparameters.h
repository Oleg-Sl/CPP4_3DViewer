#ifndef SCENEPARAMETERS_H
#define SCENEPARAMETERS_H

#include <QColor>

namespace s21 {



struct SceneParameters {
    enum TypeProjection { kCentral, kParallel};
    enum TypeEdges { kSolid, kDotted };
    enum TypeVertex { kAbsent, kCircle, kSquare };

    TypeProjection type_projection;
    QColor background_color;
    QColor edge_color;
    QColor vertex_color;
    TypeEdges edge_type;
    TypeVertex vertex_type;
    int edge_width;
    int vertex_size;
};

}

#endif // SCENEPARAMETERS_H
