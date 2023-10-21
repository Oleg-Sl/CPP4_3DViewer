#include "include/scene.h"

#include <chrono>
#include <iostream>

namespace s21 {

void Scene::TransformVertices(const TransformMatrix &matrix) {
  // auto start_time = std::chrono::steady_clock::now();
  matrix.TransformVertices(vertices_);

  // auto end_time = std::chrono::steady_clock::now();
  // auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(
  //     end_time - start_time);
  // std::cout << "Calc time: " << elapsed_ns.count() << " ms\n";
}

size_t Scene::GetCountVertices() { return vertices_.size() / 3; }

size_t Scene::GetCountEdges() { return edges_.size() * 0.5; }

NormalizationParameters Scene::GetNormalizationParams() {
  return normalization_params_;
}

void Scene::SetNormalizationParams(NormalizationParameters &&params) {
  std::swap(normalization_params_, params);
}

void Scene::SetVertices(std::vector<float> &&vertices) {
  std::swap(vertices_, vertices);
}

void Scene::SetEdges(std::vector<int> &&edges) { std::swap(edges_, edges); }

const std::vector<float> &Scene::GetVertices() { return vertices_; }

const std::vector<int> &Scene::GetEdges() { return edges_; }

}  // namespace s21
