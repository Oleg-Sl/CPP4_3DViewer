#include "include/scene.h"

namespace s21 {

std::vector<Figure> &Scene::GetFigures() { return figures_; }

void Scene::TransformFigures(const TransformMatrix &matrix) {
  for (auto& figure : figures_) {
    figure.Transform(matrix);
  }
}

void Scene::AddFigure(Figure &&figure) {
  edges_count += figure.GetEdges().size();
  verticies_count += figure.GetVertices().size();

  figures_.push_back(std::move(figure));
}

void Scene::SetBounds(Bounds bounds) { bounds_ = bounds; }

const Bounds &Scene::GetBounds() { return bounds_; }

}  // namespace s21
