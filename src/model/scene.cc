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
  edges_count += figure.GetEdges().size();
  verticies_count += figure.GetVertices().size();

  figures_.push_back(std::move(figure));
}

void Scene::SetBounds(Bounds bounds) { bounds_ = bounds; }

const Bounds &Scene::GetBounds() { return bounds_; }

}  // namespace s21
