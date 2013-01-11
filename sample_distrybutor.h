#ifndef SAMPLE_DISTRYBUTOR_H
#define SAMPLE_DISTRYBUTOR_H
#include"vector.h"
#include<math.h>
class VSampleDistributor
{
public:
    VSampleDistributor(){}
    virtual Vector2 MapSample(Vector2 sample)=0;

};

class SquareDistributor : public VSampleDistributor{
    virtual Vector2 MapSample(Vector2 v);
};

class DiskDistributor : public VSampleDistributor{
    virtual Vector2 MapSample(Vector2 sample);
};

#endif // SAMPLE_DISTRYBUTOR_H
