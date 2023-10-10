#ifndef _3DVIEWER_MODEL_FILEREADER_H_
#define _3DVIEWER_MODEL_FILEREADER_H_

#include <sstream>
#include <string>
#include <vector>

#include "scene.h"

namespace s21 {

class BaseFileReader {
 public:
  virtual Scene ReadScene(const std::string &path) = 0;
};

class OBJReader : BaseFileReader {
 public:
  const std::string kVertexToken = "v";
  const std::string kFaceToken = "f";

 public:
  Scene ReadScene(const std::string &path) override;

 private:
  void ReadVertex(std::stringstream &tokens, std::vector<Vertex> &vertices);
  void ReadFace(std::stringstream &tokens, const std::vector<Vertex> &vertices,
                Scene &scene);
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_FILEREADER_H_