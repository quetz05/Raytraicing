
#ifndef CAMERA
#define CAMERA

#include"ray.h"
#include"vector.h"

class Vcamera {
public:
	virtual VRay GetRayTo(Vector2 relativeLocation)=0;
};

class Orthogonal : public Vcamera{
public:
    Orthogonal(Vector3 eye, double angle1, Vector2 size);
    virtual VRay GetRayTo(Vector2 relativeLocation);
private:
    Vector3 eye_position;
    Vector2 camera_size;
    double angle;
};

#endif

