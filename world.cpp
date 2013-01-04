#include "world.h"
#include"hit_info.h"

World::World(QColor background){
    this->background_color=background;

}

void World::add(GeometricObject obj){
    objects.push_back(obj);
}

hit_info World::TraceRay(VRay ray){
    hit_info result;
    double minimaldistance = HUGE;//najblizsze trafienie
    //nieskonczoność
    double hit_distance = 0;//odleglosc trafienia
    for(int i =0;i<this->objects.size();++i){
        if(objects.at(i).HitTest(ray,hit_distance)
                && hit_distance<minimaldistance){
            //jesli najblizsze trafienie to przypisujemy odleglosc
            minimaldistance=hit_distance;
            result.hit_object=true;
            result.color=objects.at(i).getColor();
        }
    }
    return result;
}
