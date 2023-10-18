#include "include/scene.h"
#include <chrono>

namespace s21 {

// std::vector<Figure> &Scene::GetVertices() { return vertices_; }
// std::vector<Figure> &Scene::GetEdges() { return edges_; }

void Scene::TransformFigures(const TransformMatrix &matrix) {
  auto start_time = std::chrono::steady_clock::now();
  matrix.TransformVertices(vertices_);
  // for (auto& figure : figures_) {
  //   figure.Transform(matrix);
  // }

   auto end_time = std::chrono::steady_clock::now();
   auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
   std::cout << "Calc time: " << elapsed_ns.count() << " ms\n";
}


NormalizationParameters Scene::GetNormalizationParams() {
  return normalization_params_;
}

void Scene::SetNormalizationParams(NormalizationParameters params) {
  normalization_params_ = params;
}

} // namespace s21
