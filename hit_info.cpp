#include "hit_info.h"
#include "world.h"

HitInfo::~HitInfo(){
    delete hit_object;
    delete world;
}

HitInfo::HitInfo(){
    hit_object=NULL;
    world=NULL;
}
