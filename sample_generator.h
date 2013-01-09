#ifndef SAMPLE_GENERATOR_H
#define SAMPLE_GENERATOR_H
#include"vector.h"
#include<stdlib.h>
class VSampleGenerator{
public:
    VSampleGenerator();
    virtual void sample(Vector2 *tab,int cout)=0;
};

/****************************************************************************
 *                          Pure random generator                           *
 ****************************************************************************/
class RandomGenerator : public VSampleGenerator{
public:
    RandomGenerator(int seedl): seed(seedl){}

   virtual void sample(Vector2 *tab,int cout);
private:
    int seed;
};
/****************************************************************************
 *                          Regular generator                               *
 ****************************************************************************/
class RegularGenerator : public VSampleGenerator{
public:
    virtual void sample(Vector2 *tab,int cout);
};
/****************************************************************************
 *                          Jittered generator                              *
 ****************************************************************************/
class JitteredGenerator : public VSampleGenerator{
public:
    JitteredGenerator(int seedl): seed(seedl){}
    virtual void sample(Vector2 *tab,int cout);
private:
    int seed;
};
#endif // SAMPLE_GENERATOR_H
