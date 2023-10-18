#ifndef _3DVIEWER_MODEL_OBJREADER_H_
#define _3DVIEWER_MODEL_OBJREADER_H_

#include <sstream>
#include <string>
#include <vector>

#include "basefilereader.h"
#include "normalization_parameters.h"
#include "scene.h"

namespace s21 {

class OBJReader : public BaseFileReader {
 public:
  const std::string kVertexToken = "v";
  const std::string kFaceToken = "f";

 public:
  Scene ReadScene(const std::string &path) override;

 private:
  void ReadFace(std::stringstream &tokens, std::vector<int> &edges,
                size_t count_vertices);
  void Read3DCoords(std::stringstream &tokens, std::vector<float> &vertices);
  void CalculateNormalizationParams(const std::vector<float> &vertices, Scene &scene);
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_OBJREADER_H_
