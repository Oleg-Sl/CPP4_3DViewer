#include "include/scene.h"

namespace s21 {

std::vector<Figure> &Scene::GetFigures() { return figures_; }

void Scene::TransformFigures(const TransformMatrix &matrix) {
  for (auto figure : figures_) {
    figure.Transform(matrix);
  }
}

void Scene::AddFigure(Figure &&figure) {
  edges_count_ += figure.GetEdges().size();
  verticies_count_ += figure.GetVertices().size();

  figures_.push_back(std::move(figure));
}

NormalizationParameters Scene::GetNormalizationParams() {
  return normalization_params_;
}

void Scene::SetNormalizationParams(NormalizationParameters params) {
  normalization_params_ = params;
}

} // namespace s21
