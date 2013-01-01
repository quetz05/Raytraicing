#include"ray.h"
#include"vector.h"

#ifndef CAMERA
#define CAMERA
class Vcamera{
public:
	virtual Ray GetRayTo(Vector2 relativeLocation); 
};
class Orthogonal : Vcamera{
public:
    orthogonal(Vector3 eye, double angle1, Vector2 size);
    virtual Ray GetRayTo(Vector2 relativeLocation);
private:
    Vector3 eye_position;
    Vector2 camera_size;
    double angle;
}

#endif

