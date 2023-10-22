#ifndef _3DVIEWER_MODEL_INCLUDE_BASEFILEREADER_H_
#define _3DVIEWER_MODEL_INCLUDE_BASEFILEREADER_H_

#include "normalization_parameters.h"
#include "scene.h"

namespace s21 {

class BaseFileReader {
 public:
  virtual Scene ReadScene(const std::string &) const = 0;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_INCLUDE_BASEFILEREADER_H_
