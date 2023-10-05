#ifndef _3DVIEWER_MODEL_FILEREADER_H_
#define _3DVIEWER_MODEL_FILEREADER_H_

#include "scene.h"

#include <string>

namespace s21 {

class BaseFileReader {
public:
  virtual Scene ReadScene(std::string path) = 0;
};

class OBJReader : BaseFileReader {
public:
  Scene ReadScene(std::string path) override;
};

} // namespace s21

#endif // _3DVIEWER_MODEL_FILEREADER_H_