#include "filereader.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace s21 {
Scene OBJReader::ReadScene(std::string path) {
  Scene scene;
  std::ifstream obj_file;

  obj_file.open(path);

  if (obj_file.is_open()) {
    std::string curr_str;

    while (std::getline(obj_file, curr_str)) {
      std::stringstream ss(curr_str);

      std::string curr_lexem;
      while (std::getline(ss, curr_lexem, ' ')) {
        std::cout << curr_lexem << std::endl;
      }
    }
  } else {
    std::cout << "No file";
  }

  return scene;
}
} // namespace s21