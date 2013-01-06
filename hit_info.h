#ifndef HIT_INFO_H
#define HIT_INFO_H

#include "world.h"
#include "vector.h"

class HitInfo{


    public:

        //GeometricObject hit_object;
        //World world(QColor(255,255,255));
        Vector3 normal;
        Vector3 hit_point;
        //VRay ray;

    bool hit_object;
    QColor color;
};

#endif // HIT_INFO_H
