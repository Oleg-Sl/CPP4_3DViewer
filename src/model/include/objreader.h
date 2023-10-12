#ifndef _3DVIEWER_MODEL_OBJREADER_H_
#define _3DVIEWER_MODEL_OBJREADER_H_

#include <sstream>
#include <string>
#include <vector>

#include "basefilereader.h"
#include "normalization_parameters.h"
#include "scene.h"

namespace s21 {

class OBJReader : BaseFileReader {
public:
  const std::string kVertexToken = "v";
  const std::string kFaceToken = "f";

public:
  Scene ReadScene(const std::string &path) override;

private:
  Vertex ReadVertex(std::stringstream &tokens);
  Figure ReadFace(std::stringstream &tokens,
                  const std::vector<Vertex> &vertices);
  void CalculateNormalizationParams(const Vertex &vertex, Scene &scene);
};

} // namespace s21

#endif // _3DVIEWER_MODEL_OBJREADER_H_