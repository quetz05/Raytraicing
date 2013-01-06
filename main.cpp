#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"


int main(int argc, char *argv[])
{


    // stworzenie świata, kolor tła - biały
    World world(QColor(185,211,238));

    //dodanie kul
     world.add(new Sphere(Vector3(-4, 0, 0), 2, QColor(255,0,0)));
     world.add(new Sphere(Vector3(4, 0, 0), 2, QColor(0,255,0)));
     world.add(new Sphere(Vector3(0, 0, 3), 2, QColor(0,0,255)));

     world.add(new Plane(Vector3(0,-2,0),Vector3(0,1,0),QColor(84,84,84)));

    //Orthogonal camera(Vector3(0, 0, -5), 0, Vector2(5, 5));
     PinholeCamera camera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,0),1);
    Raytracer tracer;

    // Raytracing!
    QImage image = tracer.RayTrace(world, camera, QSize(300, 300));


    QApplication a(argc, argv);
    MainWindow w;

    w.show_image(image);
    w.show();
    
    return a.exec();
}
