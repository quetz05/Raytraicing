#include "world.h"
#include"hit_info.h"

/**definicja konstruktora klasy World*/
World::World(QColor background){
    this->background_color=background;

}

/**definicja metody add klasy World*/
void World::add(GeometricObject *obj){
    objects.push_back(obj);
}

/**definicja metody zwracającaej kolor tła*/
QColor World::get_bg_color(){
   return background_color;
}


/**definicja metody TraceRay klasy World*/
HitInfo World::TraceRay(VRay ray){

    HitInfo result;
    result.hit_object=false;
    double minimaldistance = HUGE;//najblizsze trafienie
    //nieskonczoność
    //ostatnia odległość trafienia
    double hit_distance = 0;

    for(int i =0 ;i < this->objects.size(); ++i){
        if(objects[i]->hit_test(ray,hit_distance)&& hit_distance<minimaldistance){
            //jesli najblizsze trafienie to przypisujemy odleglosc
            minimaldistance=hit_distance;
            result.hit_object=true;
            result.color=objects[i]->getColor();
        }
    }
    return result;
}
