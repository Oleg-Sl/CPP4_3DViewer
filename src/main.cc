
#include "../view/include/mainwindow.h"
#include "model/scene.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

// #include "model/edge.h"
// #include "model/scene.h"


// int main() {
//     // Point3D p{0.5, 0.5, 0.5};
//     // Point3D p2 = p;
//     // Vertex p(Point3D{0.5, 0.5, 0.5});
//     // Figure({
//     //     Point3D{0.5, 0.5, 0.5}, 
//     //     Point3D{0.5, 0.5, 0.5}, 
//     //     Point3D{0.5, 0.5, 0.5}
//     // });
//     Scene scene;
//     scene.AddFigure({
//         Point3D{ 0.5,  0.5, 0.5},
//         Point3D{ 0.5, -0.5, 0.5}, 
//         Point3D{-0.5, -0.5, 0.5},
//         Point3D{-0.5,  0.5, 0.5}
//     });
//     // scene.AddFigure(
//     //     0.5, 0.5, 0.5,
//     //     -0.5, 0.5, 0.5,
//     //     -0.5, -0.5, 0.5,
//     //     0.5, -0.5, 0.5,
//     //     0.5, 0.5, -0.5,
//     //     -0.5, 0.5, -0.5,
//     //     -0.5, -0.5, -0.5,
//     //     0.5, -0.5, -0.5,
//     // );
//     return 0;
// }
