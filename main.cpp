#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"


int main(int argc, char *argv[])
{


    // world.add(new Plane(Vector3(0,-2,0),Vector3(0,1,0),ref_gray_mat));
    // world.add_light(PointLight(Vector3(0,5,-5), MyColor(0.5,0.5,0.5), &distributor,0.5));

    QApplication a(argc, argv);
    MainWindow w;

    w.new_world();
    w.show();
    
    return a.exec();
}
