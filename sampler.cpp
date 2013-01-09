#include "sampler.h"

Sampler::Sampler(VSampleGenerator sampler, VSampleDistributor mapper, int sampleCt, int setCt){
    seed=0;
    this->sampleCout=sampleCt;
    for(int i=0;i<setCt;++i){
        Vector2* samples = new Vector2[sampleCt];
        sampler.sample(samples,sampleCt);// tu losujemy ilość próbek
        for(int j=0;j<sampleCt;++j){//tu je mapujemy na dowolną powiezchnie
            samples[j]=mapper.MapSample(samples[j]);
        }
        sets.push_back(samples);

    }
}
