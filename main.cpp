#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include "geometric_objects.h"
#include "raytracer.h"
#include "camera.h"


int main(int argc, char *argv[])
{


    // stworzenie świata
   World world(QColor(135, 206, 250));


    // Material *ref_gray_mat = new Reflective(QColor(84,84,84), 0.4, 1, 300, 0.6);

    // world.add(new Plane(Vector3(0,-2,0),Vector3(0,1,0),ref_gray_mat));

     JitteredGenerator gener(0);
     SquareDistributor dist;
     Sampler distributor(gener,dist,1,60,0);


     //PointLight light(Vector3(0, 5, -5), QColor(255,255,255));

     PointLight light (Vector3(0,5,-5), MyColor(0.5,0.5,0.5), &distributor,0.5);

     world.add_light(light);



     LensCamera camera (Vector3(0,1,-10),Vector3(0,0,0),Vector3(0,-1,0),Vector2(2,1.5),2,&distributor,0.5,11);
     Raytracer tracer(5);

    // Raytracing!
   QImage image = tracer.RayTrace(world, camera, QSize(800, 600),&distributor);



    QApplication a(argc, argv);
    MainWindow w;
   w.adding_things(image, world);

    //w.new_world();
    w.show();
    
    return a.exec();
}
