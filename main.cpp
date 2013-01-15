#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"


int main(int argc, char *argv[])
{

    World world(QColor(0,180,180));

    int samples = 1;

    Material *material = new Reflective (QColor(2,255,255), 0.4, 1, 300, 0.6);
    PinholeCamera camera(Vector3(0,0,0),Vector3(0,0,1),Vector3(0,-1,0),Vector2(1,0.75),1);


    world.add(new Sphere(Vector3(-2,-1.15,1), 2,  material));
    world.add(new Sphere(Vector3(2,-1.15,1), 2,  material));
    world.add(new Sphere(Vector3(0,3.45-1.15,1), 2,  material));
    world.add(new Sphere(Vector3(0,1.15-1.15,3.45+1), 2,  material));

    JitteredGenerator gener(0);
    SquareDistributor dist;
    Sampler distributor(gener,dist,samples,60,0);




    world.add_light(PointLight(Vector3(0,0,3.45-2), MyColor(1,1,1)));

    Raytracer tracer(5);
    QImage image;
    image = tracer.ray_trace(world, camera, QSize(800, 600), &distributor);




    QApplication a(argc, argv);
    MainWindow w;

    w.copy_world(image, world);
    w.show_image();
   // w.new_world();
    w.show();
    
    return a.exec();
}
