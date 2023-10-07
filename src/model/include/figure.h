//#ifndef _3DVIEWER_MODEL_FIGURE_H_
//#define _3DVIEWER_MODEL_FIGURE_H_

//#include "scene_object.h"
//#include "transform_matrix.h"
//#include "vertex.h"
//#include "edge.h"
//#include "point_3d.h"

//#include <vector>


//namespace s21 {

//class Figure : public SceneObject {
//public:
//    // template<typename... Args>
//    // void Figure(Args&&... points) {
//    //     (figures.push_back(std::forward<Args>(points)), ...);
//    // }
//    Figure(std::initializer_list<Point3D> points) {
//        for (auto point : points) {
//            vertices.push_back(point);
//        }
//    }
//    std::vector<Vertex>& GetVertices();
//    std::vector<Edge>& GetEdges();
//    void Transform(const TransformMatrix&);

//private:
//    std::vector<Vertex> vertices;
//    std::vector<Edge> edges;
//};

//}

//#endif  // _3DVIEWER_MODEL_FIGURE_H_



 #ifndef _3DVIEWER_MODEL_FIGURE_H_
 #define _3DVIEWER_MODEL_FIGURE_H_

 #include <vector>

 #include "edge.h"
 #include "scene_object.h"
 #include "transform_matrix.h"
 #include "vertex.h"

 namespace s21 {

 class Figure : public SceneObject {
  public:
   std::vector<Vertex>& GetVertices();
   std::vector<Edge>& GetEdges();
   void Transform(const TransformMatrix&);
   void AddEdge(const Edge& edge);
   void PrintEdges() const;

  private:
   std::vector<Vertex> vertices_;
   std::vector<Edge> edges_;
 };

 }  // namespace s21

 #endif  // _3DVIEWER_MODEL_FIGURE_H_
