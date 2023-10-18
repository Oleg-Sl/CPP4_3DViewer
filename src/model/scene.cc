#include "include/scene.h"

#include <chrono>
#include <iostream>

namespace s21 {

void Scene::TransformVertices(const TransformMatrix &matrix) {
  auto start_time = std::chrono::steady_clock::now();
  matrix.TransformVertices(vertices_);

  auto end_time = std::chrono::steady_clock::now();
  auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  std::cout << "Calc time: " << elapsed_ns.count() << " ms\n";
}

NormalizationParameters Scene::GetNormalizationParams() {
  return normalization_params_;
}

void Scene::SetNormalizationParams(NormalizationParameters params) {
  normalization_params_ = params;
}

void Scene::SetVertices(std::vector<float> &&vertices) {
  vertices_ = std::move(vertices);
}

void Scene::SetEdges(std::vector<int> &&edges) { edges_ = std::move(edges); }

const std::vector<float> &Scene::GetVertices() { return vertices_; }

const std::vector<int> &Scene::GetEdges() { return edges_; }

}  // namespace s21
