#include "world.h"

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
    double minimaldistance = HUGER;//najblizsze trafienie
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

/**definicja metody obstacles*/
/*bool World::obstacles(Vector3 a, Vector3 b){

    //odl. od punktu cieniowanego do punktu światła
    Vector3 vector_ab = a - b;
    double distance_ab = vector_ab.getLength();
    double distance = HUGE;

    //promień z cieniowanego punktu do światła
    VRay ray(a, b);

    Vector3 ignored;

    //sprawdzanie czy dany obiekt jest w cieniu (jeśli tak zwróć true, jeśli nie - false)
    for(int i=0; i<objects.size();i++)
       if(objects[i].hit_test(ray, &distance, &ignored) && distance < distance_ab)
          return true;

    return false;
}*/


