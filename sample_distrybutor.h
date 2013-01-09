#ifndef SAMPLE_DISTRYBUTOR_H
#define SAMPLE_DISTRYBUTOR_H
#include"vector.h"
class VSampleDistributor
{
public:
    VSampleDistributor();
    virtual Vector2 MapSample(Vector2 sample){}

};

class SquareDistributor : public VSampleDistributor{
    virtual Vector2 MapSample(Vector2 v);
};

#endif // SAMPLE_DISTRYBUTOR_H
