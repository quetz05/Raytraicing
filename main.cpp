#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"

int main(int argc, char *argv[])
{
    // stworzenie świata, kolor tła - biały
    World world(QColor(255,255,255));

    //dodanie kul
     world.add(new Sphere(Vector3(-2.5, 0, 0), 2, QColor(255,0,0)));
   // world.add(Sphere(Vector3(2.5, 0, 0), 2, QColor(0,255,0)));
    //world.add(Sphere(Vector3(0, 0, 2.5), 2, QColor(0,0,0)));

    Orthogonal camera(Vector3(0, 0, -5), 0, Vector2(5, 5));
    Raytracer  tracer();
    // Raytracing!
   // QImage image = tracer.RayTrace(world, camera, QSize(256, 256));



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
