/**plik nagłówkowy zawierający implementację klasy HitInfo*/
#ifndef HIT_INFO_H
#define HIT_INFO_H
#include "vector.h"
#include "geometric_objects.h"

class World;

/**
 * @brief HitInfo klasa pomocnicza przechowująca informacje o trafieniu
 */
class HitInfo{

    public:

        /**
         * @brief depth zmienna określająca głębię, zwiększana przy śledzeniu odbitego lub załamanego promienia
         */
        int depth;
        /**
         * @brief HitInfo konstruktor bezargumentowy
         */
        HitInfo(){hit_object=NULL; world=NULL;}
        /**
         * @brief ~HitInfo destruktor klasy HitInfo
         */
       // ~HitInfo(){delete hit_object; delete world;}
        /**
         * @brief normal zmienna określająca normalną
         */
        Vector3 normal;
        /**
         * @brief hit_point zmienna określająca trafiony punkt
         */
        Vector3 hit_point;
        /**
         * @brief ray zmienna określająca promień
         */
        VRay ray;
        /**
         * @brief world wskaźnik na świat
         */
        World *world;
        /**
         * @brief hit_object wskaźnik na trafiany obiekt geometryczny
         */
        GeometricObject *hit_object;

};


#endif // HIT_INFO_H
