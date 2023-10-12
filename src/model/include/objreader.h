#ifndef _3DVIEWER_MODEL_FILEREADER_H_
#define _3DVIEWER_MODEL_FILEREADER_H_

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
  Scene ReadScene(
      const std::string &path,
      const NormalizationParameters &normalization_parameters) override;

 private:
  Vertex ReadVertex(std::stringstream &tokens);
  Figure ReadFace(std::stringstream &tokens,
                  const std::vector<Vertex> &vertices);
  void NormalizationScene(Scene &scene, const NormalizationParameters &params);
  void CalculateSceneBounds(Scene &scene, const Vertex &vertex);
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_FILEREADER_H_