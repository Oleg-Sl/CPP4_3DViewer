#ifndef _3DVIEWER_MODEL_SCENE_H_
#define _3DVIEWER_MODEL_SCENE_H_

#include "figure.h"
#include "transform_matrix.h"

#include <vector>


class Scene {
public:
    std::vector<Figure>& GetFigures();
    void TransformFigures(const TransformMatrix&);

private:
    std::vector<Figure> figures;
};

#endif  // _3DVIEWER_MODEL_SCENE_H_
