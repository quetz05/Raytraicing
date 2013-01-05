#include <QColor>
/*#include "world.h"
#include "vector.h"
#include "geometric_objects.h"
#include "ray.h"*/
#ifndef HIT_INFO_H
#define HIT_INFO_H



struct HitInfo{


  /*  public:

        GeometricObject hit_object;
        World world;
        Vector3 normal;
        Vector3 hit_point;
        VRay ray;
        */
    bool hit_object;
    QColor color;
};

#endif // HIT_INFO_H
