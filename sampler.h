#ifndef SAMPLER_H
#define SAMPLER_H
#include<QList>
#include"sample_generator.h"
#include"sample_distrybutor.h"
class Sampler{
public:
    Sampler(VSampleGenerator& sampler,VSampleDistributor& mapper,
            int sampleCt,int setCt);
    Vector2 Single();
    int getSampleCout(){return sampleCout;}
private:
    int seed;
    QList<Vector2*> sets;
    int sampleNdx;
    int setNdx;
    int sampleCout;
    int setCout;

};

#endif // SAMPLER_H
