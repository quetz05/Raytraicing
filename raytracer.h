#ifndef RAYTRACER_H
#define RAYTRACER_H
#include<QPixmap>
#include "vector.h"
#include "world.h"
#include "camera.h"
#include "materials.h"

/**klasa, która śledzi promień dla każdego piksela*/
class Raytracer {

    public:

    /**tworzenie obrazu wynikowego*/
    QImage RayTrace(World world, Vcamera &camera, QSize image_size);
    /**funkcja sumująca światło*/
    QColor shaderay(World world, VRay ray);


};

#endif // RAYTRACER_H
