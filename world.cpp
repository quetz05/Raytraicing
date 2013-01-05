#include "world.h"
#include"hit_info.h"

/**definicja konstruktora klasy World*/
World::World(QColor background){
    this->background_color=background;

}

/**definicja metody add klasy World*/
void World::add(GeometricObject obj){
    objects.push_back(obj);
}

/**definicja metody TraceRay klasy World*/
HitInfo World::TraceRay(VRay ray){

    HitInfo result;
    double minimaldistance = HUGE;//najblizsze trafienie
    //nieskonczoność
    //ostatnia odległość trafienia
    double hit_distance = 0;

    for(int i =0 ;i < this->objects.size(); ++i){
        if((objects[i]).HitTest(ray,hit_distance)&& hit_distance<minimaldistance){
            //jesli najblizsze trafienie to przypisujemy odleglosc
            minimaldistance=hit_distance;
            result.hit_object=true;
            result.color=(objects[i]).getColor();
        }
    }
    return result;
}
