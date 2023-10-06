#include "scene.h"

namespace s21 {

std::vector<Figure>& Scene::GetFigures() { return figures_; }

void Scene::TransformFigures(const TransformMatrix& matrix) {
  for (auto figure : figures_) {
    figure.Transform(matrix);
  }
}

void Scene::AddFigure(const Figure& figure) { figures_.push_back(figure); }

}  // namespace s21