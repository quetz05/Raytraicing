#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"


int main(int argc, char *argv[])
{


    // stworzenie świata
    World world(QColor(220,210,220));

    //materiały
    Material *red_mat = new PerfectDiffuse(QColor(255,0,0));
    Material *green_mat = new PerfectDiffuse(QColor(0,255,0));
    Material *blue_mat = new PerfectDiffuse(QColor(0,0,255));
    Material *gray_mat = new PerfectDiffuse(QColor(84,84,84));

    Material *phong_green_mat = new Phong(QColor(0,255,0), 0.8, 1, 30);


     //dodanie kul
        world.add(new Sphere(Vector3(-4, 0, 0), 2, blue_mat));
     world.add(new Sphere(Vector3(4, 0, 0), 2, phong_green_mat));
     world.add(new Sphere(Vector3(0, 0, 3), 2, red_mat));

    world.add(new Plane(Vector3(0,-2,0),Vector3(0,1,0),gray_mat));

     PointLight light(Vector3(0, 5, -5), QColor(255,255,255));

     world.add_light(light);

     //Orthogonal camera(Vector3(0, 0, -5), 0, Vector2(5, 5));
     PinholeCamera camera(Vector3(0,1,-8),Vector3(0,0,0),Vector3(0,-1,0),Vector2(1,0.75),1);
     Raytracer tracer;

    // Raytracing!
    QImage image = tracer.RayTrace(world, camera, QSize(800, 600));


    QApplication a(argc, argv);
    MainWindow w;

    w.show_image(image);
    w.show();
    
    return a.exec();
}
