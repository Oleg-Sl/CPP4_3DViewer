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
  std::vector<size_t> ReadFace(std::stringstream &tokens,
                                          size_t count_vertices);
  void ReadCoord(std::stringstream &tokens,
                            std::vector<float> &vertices);
  void CalculateNormalizationParams(const Vertex &vertex, Scene &scene);
};

} // namespace s21

#endif // _3DVIEWER_MODEL_OBJREADER_H_