#include "world.h"



/**definicja konstruktora klasy World*/
World::World(QColor background){
    this->background_color=background;

}

/**definicja metody add klasy World*/
void World::add(GeometricObject *obj){
    objects.push_back(obj);
}

/**definicja metody add_light klasy World*/
void World::add_light(PointLight light){
    lights.push_back(light);
}


/**definicja metody zwracającaej kolor tła*/
QColor World::get_bg_color(){
   return background_color;
}


/**definicja metody TraceRay klasy World*/
HitInfo World::TraceRay(VRay ray){

    //rezultat śledzenie promienia
    HitInfo result;
    Vector3 normal;

    double minimal_distance = HUGER;//najblizsze trafienie
    //nieskonczoność
    //ostatnia odległość trafienia
    double hit_distance = 0;

    for(int i =0 ;i < this->objects.size(); ++i){
        if(objects[i]->hit_test(ray,hit_distance, normal)&& hit_distance<minimal_distance){
            //jesli najblizsze trafienie to przypisujemy odleglosc
            minimal_distance=hit_distance;
            result.hit_object2=objects[i];
            result.color=objects[i]->getColor();
        }
    }

     // jeśli promień trafił na cokolwiek
    if (result.hit_object2 != NULL)
    {
            result.hit_point = ray.origin + ray.direction * minimal_distance;
            result.ray = ray;
            result.world = this;
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
       if(objects[i]->hit_test(ray, &distance, &ignored) && distance < distance_ab)
          return true;

    return false;
}*/


