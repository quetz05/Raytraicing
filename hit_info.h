#ifndef HIT_INFO_H
#define HIT_INFO_H


#include "vector.h"
#include "geometric_objects.h"

class World;

class HitInfo{
public:

    GeometricObject *hit_object;
    Vector3 normal;
    Vector3 hit_point;
    VRay ray;
    World *world;

};


#endif // HIT_INFO_H
