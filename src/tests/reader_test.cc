#include "../model/filereader.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  s21::OBJReader reader;
  reader.ReadScene("/Users/varlybot/Desktop/CPP4_3DViewer_v2.0-1/src/model_examples/cube.obj");
  return 0;
}