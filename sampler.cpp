#include "sampler.h"

Sampler::Sampler(VSampleGenerator &sampler, VSampleDistributor &mapper, int sampleCt, int setCt, int seed){
    this->seed=seed;
    this->sampleCout=sampleCt;
    this->setCout=setCt;
    for(int i=0;i<setCt;++i){
        Vector2* samples = new Vector2[sampleCt];
        sampler.sample(samples,sampleCt);// tu losujemy ilość próbek
        for(int j=0;j<sampleCt;++j){//tu je mapujemy na dowolną powiezchnie
            samples[j]=mapper.MapSample(samples[j]);
        }
        sets.push_back(samples);
    }
    srand(seed);
    this->setNdx=0;
    this->sampleNdx=0;
}

Sampler::~Sampler(){
    for(int i =0;i<this->setCout;++i){

        delete [] sets[i];
    }
}
Vector2 Sampler::Single(){

    Vector2 sample = (sets[setNdx])[sampleNdx];
    sampleNdx++;
    if(sampleNdx>=sampleCout){
        sampleNdx=0;
        setNdx= (rand()/RAND_MAX);//*setCout;
    }
    return sample;
}
