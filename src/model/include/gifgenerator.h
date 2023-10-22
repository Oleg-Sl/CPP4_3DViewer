#ifndef _3DVIEWER_MODEL_INCLUDE_GIFGENERATOR_H_
#define _3DVIEWER_MODEL_INCLUDE_GIFGENERATOR_H_

#include <QImage>
#include <cstdint>
#include <string>
#include <vector>

#include "../lib/gif.h"

class GifGenerator {
 public:
  GifGenerator() {}

  void InitializeGenerator(const std::string& filename, int width, int height,
                           int fps, int duration);
  void AddFrame(const uint8_t* image);

  bool GetFinished() const;
  bool GetInitialized() const;
  int GetWidth() const;
  int GetHeight() const;
  int GetDelay() const;

  ~GifGenerator();

 private:
  GifWriter gifWriter_;
  std::string filename_;
  int width_;
  int height_;
  int fps_;
  int delay_;
  int duration_;
  int currentTime_ = 0;
  bool finished_ = false;
  bool initialized_ = false;
};

#endif  // _3DVIEWER_MODEL_INCLUDE_GIFGENERATOR_H_
