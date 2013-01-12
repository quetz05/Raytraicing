/**plik nagłówkowy zawierający implementację klasy HitInfo*/
#ifndef HIT_INFO_H
#define HIT_INFO_H
#include "vector.h"
#include "geometric_objects.h"

/**deklaracja klasy World*/
class World;

/**klasa HitInfo przechowująca informacje o trafieniach promieni*/
class HitInfo{

    public:

        /**zmienna odpowiadająca za głębię*/
        int depth;
        /**konstruktor bezargumentowy tworzący wskaźniki klasy wskazujące na NULL*/
        HitInfo(){hit_object=NULL; world=NULL;}
        /**destruktor klasy HitInfo*/
        //~HitInfo(){delete hit_object; delete world;}
        /**zmienna określająca normalną*/
        Vector3 normal;
        /**zmienna określająca punkt trafienia*/
        Vector3 hit_point;
        /**zmienna określająca promień*/
        VRay ray;
        /**wskaźnik na świat*/
        World *world;
        /**wskaźnik na obiekt geometryczny*/
        GeometricObject *hit_object;

};


#endif // HIT_INFO_H
