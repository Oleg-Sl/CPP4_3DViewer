#ifndef _3DVIEWER_MODEL_FILEREADER_H_
#define _3DVIEWER_MODEL_FILEREADER_H_

#include <string>

#include "scene.h"

namespace s21 {

class BaseFileReader {
 public:
  virtual Scene ReadScene(std::string path) = 0;
};

class OBJReader : BaseFileReader {
 public:
  const std::string kVertexToken = "v";
  const std::string kFaceToken = "f";

  Scene ReadScene(std::string path) override;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_FILEREADER_H_