
#ifndef CAMERA
#define CAMERA

#include"ray.h"
#include"vector.h"

class Vcamera{
public:
    virtual VRayy GetRayTo(Vector2 relativeLocation);
}:

class Orthogonal : Vcamera{
public:
    orthogonal(Vector3 eye, double angle1, Vector2 size);
    virtual VRayy GetRayTo(Vector2 relativeLocation);
private:
    Vector3 eye_position;
    Vector2 camera_size;
    double angle;
}

#endif

