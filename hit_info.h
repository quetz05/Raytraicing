#ifndef HIT_INFO_H
#define HIT_INFO_H


#include "vector.h"
#include "geometric_objects.h"

class World;

class HitInfo{
public:

    GeometricObject *hit_object2;
    Vector3 normal;
    Vector3 hit_point;
    VRay ray;
    World *world;
    bool hit_object;
    QColor color;
};


#endif // HIT_INFO_H
