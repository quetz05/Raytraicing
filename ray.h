#ifndef RAY
#define RAY

#include <limits>
#include "vector.h"


#define EPSILON 0.00001
#define HUGER std::numeric_limits<double>::max();
class VRay{
public:
    inline VRay(Vector3 &origin, Vector3 &direction){
        this->origin = origin;
        this->direction = direction.normalized();
    }

    inline VRay(){
        origin = Vector3();
        direction = Vector3();
    }

    Vector3 origin;
    Vector3 direction;
};
#endif
