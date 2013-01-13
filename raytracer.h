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

    Raytracer(){max_depth = 1;}

    inline Raytracer(int depth){max_depth=depth;}

    //inline int get_max_depth(){return max_depth;}

    /**tworzenie obrazu wynikowego*/
    QImage RayTrace(World world, Vcamera &camera, QSize image_size, Sampler* distributor);
    /**funkcja sumująca światło*/
    MyColor shaderay(World world, VRay ray, int current_depth);

private:
    int max_depth;



};

#endif // RAYTRACER_H
