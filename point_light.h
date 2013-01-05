#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H
#include "vector.h"
#include <QColor>

/**struktura reprezentująca światło punktowe*/
class PointLight{

    public:
        /**konstruktor tworzący światło punktowe o danym kolorze w danym miejscu*/
        PointLight(Vector3 n_position,QColor n_color){color=n_color; position=n_position;}
        /**konstruktor kopiujący*/
        PointLight(PointLight &l): color(l.color),position(l.position){}
        /**metoda zwracająca pozycję punktu światła*/
        Vector3 get_position(){return position;}
        /**metoda zwracająca kolor światła*/
        QColor get_color(){return color;}



    private:

        /**pozycja punktu w przestrzeni*/
        Vector3 position;
        /**kolor światła*/
        QColor color;

};

#endif // POINT_LIGHT_H
