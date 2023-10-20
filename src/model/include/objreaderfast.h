#ifndef _3DVIEWER_MODEL_INCLUDE_OBJREADERFAST_H_
#define _3DVIEWER_MODEL_INCLUDE_OBJREADERFAST_H_

#include <string>
#include <vector>

#include "basefilereader.h"
#include "normalization_parameters.h"
#include "scene.h"

namespace s21 {

class OBJReaderFast : public BaseFileReader {
 public:
  const char kVertexToken = 'v';
  const char kFaceToken = 'f';

 public:
  Scene ReadScene(const std::string &path) override;

 private:
  void ReadFace(const char *str, std::vector<int> &edges,
                size_t count_vertices);
  void ReadVertices(const char *line, std::vector<float> &vertices);
  void CalculateNormalizationParams(const std::vector<float> &vertices,
                                    Scene &scene);

  const int kMaxLineLength = 256;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_INCLUDE_OBJREADERFAST_H_
