#include <limits>
#include "vector.h"
#ifndef RAY
#define RAY
#define EPSILON 0.00001
#define HUGE numeric_limits<double>::max();
struct Ray{
    public ray(Vector3 origin,Vector3 direction){
        this->Origin=origin;
        this->Direction=direction
    }
    public Vector3 Origin;
    public Vector3 Direction;

}
#endif
