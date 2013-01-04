#include <limits>
#include "vector.h"

#ifndef RAY
#define RAY
#define EPSILON 0.00001
#define HUGE numeric_limits<double>::max();
class VRay{
public:
    inline VRay(Vector3 &origin, Vector3 &direction){
        this->origin = origin;
        this->direction = direction;
    }

    Vector3 origin;
    Vector3 direction;
};
#endif
