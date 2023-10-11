#include "normalization_parameters.h"
#include "scene.h"

namespace s21 {

class BaseFileReader {
 public:
  virtual Scene ReadScene(
      const std::string &path,
      const NormalizationParameters &normalization_parameters) = 0;
};
}  // namespace s21