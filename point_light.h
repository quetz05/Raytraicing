#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H
#include "vector.h"
#include"sampler.h"
#include "mycolor.h"
#include<stdlib.h>

/**
 * @brief The PointLight class klasa reprezentujaca swiatlo punktowe i kule
 */
class PointLight{

    public:
    /**
     * @brief PointLight konstruktor tworzacy swiatlo punktowe o danym koloze w danym miejscu
     * @param n_position pozycja swiatla
     * @param n_color kolor swiatla
     */
    PointLight(Vector3 n_position,MyColor n_color):color(n_color),center(n_position),radius(0){}
    /**
     * @brief PointLight konstruktor tworzacy swiatlo jako kule
     * @param n_position pozycja swiatla
     * @param n_color kolor swiatla
     * @param dist sampler dzieki ktoremu losujemy probki na powiezchni kuli
     * @param radiuss promien kuli swiatla
     */
    PointLight(Vector3 n_position, MyColor n_color,Sampler* dist,double radiuss):
        center(n_position),color(n_color),radius(radiuss),distributor(dist){}
    /**
     * @brief PointLight konstruktor kopiujacy swiatla
     * @param light swiatlo
     */
    PointLight(const PointLight &light):center(light.center), color(light.color),radius(light.radius),distributor(light.distributor){}
    /**
     * @brief get_position metoda zwracajaca pozycje swiatla
     * @return  pozycja swiatla w przestrzeni
     */
    Vector3 get_position();
    /**
     * @brief get_color metoda zwracajaca kolor swiatla
     * @return kolor swiatla
     */
    MyColor get_color(){return color;}
    /**
     * @brief RemapSampleToSphere metoda przeliczajaca wylosowana probke tak aby ta lezala na powiezchni kuli
     * @param sample probka do przeliczenia
     * @return
     */
    Vector3 RemapSampleToSphere(Vector2 sample);


    private:

    /**
     * @brief center punkt w ktorym lezy swiatlo
     */
    Vector3 center;
    /**
     * @brief color kolor swiatla
     */
    MyColor color;
    /**
     * @brief radius promien kuli swiatla
     */
    double radius;
    /**
     * @brief distributor sampler z zestawem probek
     */
    Sampler* distributor;

};


#endif // POINT_LIGHT_H
