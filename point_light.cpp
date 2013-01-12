#include"point_light.h"
#define _USE_MATH_DEFINES
#include<math.h>
Vector3 PointLight::get_position(){
    if(radius==0)return center;
    Vector2 sample = distributor->Single();
    return center+RemapSampleToSphere(sample)*radius;
}

Vector3 PointLight::RemapSampleToSphere(Vector2 sample){
    double z = 2*sample.x -1;
    double t = 2*M_PI*sample.y;
    double r = sqrt(1-z*z);
    return Vector3(r*cos(t),r*sin(t),z);
}
