#ifndef _3DVIEWER_MODEL_BOUNDS_H_
#define _3DVIEWER_MODEL_BOUNDS_H_

namespace s21 {

struct Bounds {
  float min_vertex_x_value = 0;
  float max_vertex_x_value = 0;
  float min_vertex_y_value = 0;
  float max_vertex_y_value = 0;
  float min_vertex_z_value = 0;
  float max_vertex_z_value = 0;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_BOUNDS_H_
