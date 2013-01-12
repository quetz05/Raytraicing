#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H
#include "vector.h"
#include"sampler.h"
#include "mycolor.h"
#include<stdlib.h>

/**struktura reprezentująca światło punktowe*/
class PointLight{

    public:
        /**konstruktor tworzący światło punktowe o danym kolorze w danym miejscu*/
    PointLight(Vector3 n_position,MyColor n_color):color(n_color),center(n_position),radius(0){}
    PointLight(Vector3 n_position, MyColor n_color,Sampler* dist,double radiuss):
        center(n_position),color(n_color),radius(radiuss),distributor(dist){}
        /**konstruktor kopiujący*/
    PointLight(const PointLight &light):center(light.center), color(light.color),radius(light.radius),distributor(light.distributor){}
        /**metoda zwracająca pozycję punktu światła*/
        Vector3 get_position();
        /**metoda zwracająca kolor światła*/
        MyColor get_color(){return color;}
        Vector3 RemapSampleToSphere(Vector2 sample);


    private:

        /**pozycja punktu w przestrzeni*/
        Vector3 center;
        /**kolor światła*/
        MyColor color;
        double radius;
        Sampler* distributor;

};


#endif // POINT_LIGHT_H
