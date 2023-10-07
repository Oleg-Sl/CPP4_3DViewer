#include "include/scene.h"

namespace s21 {

std::vector<Figure> &Scene::GetFigures() { return figures_; }

void Scene::TransformFigures(const TransformMatrix &matrix) {
  for (auto figure : figures_) {
    figure.Transform(matrix);
  }
}

void Scene::AddFigure(Figure &&figure) {
  figures_.push_back(std::move(figure));
}

} // namespace s21