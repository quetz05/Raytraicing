#include "sample_generator.h"
#include"math.h"



void RandomGenerator::sample(Vector2 *tab,int cout){
    srand(this->seed);
    for(int i=0;i<cout;++i){
        tab[i]=Vector2((double)rand()/(double)RAND_MAX,(double)rand()/(double)RAND_MAX);
    }
}

void RegularGenerator::sample(Vector2 *tab,int cout){
    int row= (int)sqrt(cout);
    for(int x=0;x<row;++x){
        for(int y=0;y<row;++y){
            double lx = (x+0.5)/ row;
            double ly = (y+0.5)/ row;
            tab[x*row+y]=Vector2(lx,ly);
        }
    }
}
void JitteredGenerator::sample(Vector2 *tab,int cout){
    int row= (int)sqrt(cout);
    for(int x=0;x<row;++x){
        for(int y=0;y<row;++y){
            double lx = (x+(double)rand()/(double)RAND_MAX)/ row;
            double ly = (y+(double)rand()/(double)RAND_MAX)/ row;
            tab[x*row+y]=Vector2(lx,ly);
        }
    }
}
