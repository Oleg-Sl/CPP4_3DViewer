#include "include/objreaderfast.h"

#include <cstring>
#include <locale>

namespace s21 {

void OBJReaderFast::CalculateNormalizationParams(const std::vector<float>& vertices,
                                             Scene& scene) {
  NormalizationParameters params = scene.GetNormalizationParams();

  float x = abs(vertices[vertices.size() - 1]);
  float y = abs(vertices[vertices.size() - 2]);
  float z = abs(vertices[vertices.size() - 3]);

  float max = std::max(x, std::max(y, z));
  params.max = std::max(max, params.max);
  params.min = -params.max;
  params.step = params.max / 100.0 * 5.0;

  scene.SetNormalizationParams(std::move(params));
}

void OBJReaderFast::ReadFace(const char* str, std::vector<int>& edges,
                         size_t count_vertices) {
  char* cstr = strdup(str);
  char* token = strtok(cstr, " ");
  std::vector<int> added_vertices;

  while (token != NULL) {
    char temp[kMaxLineLength];
    int temp_index = 0;

    while ((token[0] == '-' || isdigit(*token)) && *token != '\0') {
      temp[temp_index++] = *token;
      token++;
    }

    temp[temp_index] = '\0';

    if (temp[0] != '\0') {
      int vertex_index = atoi(temp);

      if (vertex_index < 0) {
        vertex_index = count_vertices + vertex_index;
      } else {
        vertex_index -= 1;
      }
      if (vertex_index < 0 ||
          vertex_index >= static_cast<int>(count_vertices)) {
        throw std::invalid_argument("Invalid face index: " +
                                    std::to_string(vertex_index));
      }
      added_vertices.push_back(vertex_index);
    }

    token = strtok(NULL, " ");
  }

  int size = static_cast<int>(added_vertices.size());
  for (int i = 0; i < size; ++i) {
    int start = i;
    int end = (i + 1 == size) ? 0 : i + 1;

    edges.push_back(added_vertices[start]);
    edges.push_back(added_vertices[end]);
  }

  free(cstr);
}

void OBJReaderFast::ReadVertices(const char* line, std::vector<float>& vertices) {
  float x, y, z;
  if (std::sscanf(line, "v %f %f %f", &x, &y, &z) == 3) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
  }
}

Scene OBJReaderFast::ReadScene(const std::string& path) {
  std::setlocale(LC_ALL, "C");
  Scene scene;
  std::vector<float> vertices;
  std::vector<int> edges;

  FILE* obj_file = fopen(path.c_str(), "r");
  if (obj_file) {
    char line[kMaxLineLength];
    while (fgets(line, sizeof(line), obj_file)) {
      if (line[0] != '\0') {
        char firstChar = line[0];
        if (firstChar == kVertexToken) {
          ReadVertices(line, vertices);
          CalculateNormalizationParams(vertices, scene);
        } else if (firstChar == kFaceToken) {
          ReadFace(line, edges, vertices.size() / 3);
        }
      }
    }
    fclose(obj_file);
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }

  scene.SetVertices(std::move(vertices));
  scene.SetEdges(std::move(edges));

  return scene;
}

}  // namespace s21
