#include "include/scene.h"

namespace s21 {

std::vector<Figure> &Scene::GetFigures() { return figures_; }

void Scene::TransformFigures(const TransformMatrix &matrix) {
   auto start_time = std::chrono::steady_clock::now();

  for (auto& figure : figures_) {
    figure.Transform(matrix);
  }

   auto end_time = std::chrono::steady_clock::now();
   auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
   std::cout << "Calc time: " << elapsed_ns.count() << " ms\n";
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
