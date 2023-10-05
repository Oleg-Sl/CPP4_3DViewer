#include "scene.h"


std::vector<Figure>& Scene::GetFigures() {
    return figures;
}

void Scene::TransformFigures(const TransformMatrix& matrix) {
    for (auto figure : figures) {
        figure.Transform(matrix);
    }
}
