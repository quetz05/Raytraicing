#include"sample_distrybutor.h"
#define _USE_MATH_DEFINES
#include <math.h>

Vector2 SquareDistributor::MapSample(Vector2 v){
    return v;
}


Vector2 DiskDistributor::MapSample(Vector2 sample){
return Vector2(
        sample.x*cos(sample.y*M_PI),
        sample.x*sin(sample.y*M_PI));

}
