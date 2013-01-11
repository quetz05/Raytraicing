#ifndef HIT_INFO_H
#define HIT_INFO_H


#include "vector.h"
#include "geometric_objects.h"

class World;

class HitInfo{
public:

    //~HitInfo(){delete world; delete hit_object;}
    HitInfo(){hit_object=NULL; world=NULL;}
    GeometricObject *hit_object;
    Vector3 normal;
    Vector3 hit_point;
    VRay ray;
    World *world;
    int depth;

};


#endif // HIT_INFO_H
