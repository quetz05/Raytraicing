/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#ifndef GEO_OBJECTS
#define GEO_OBJECTS

#include "ray.h"
#include <QColor>


/**klasa bazowa figury geometrycznej*/
class GeometricObject {

    public:

        /**funkcja sprawdzająca czy promień trafił w figurę*/
        virtual bool const HitTest(VRay ray, double &distance);
        /**funkcja zwracająca kolor figury*/
        QColor getColor();
        /**funkcja ustawiająca kolor figury*/
        void setColor(QColor newColor);

    protected:

        //kolor figury
        QColor color;

};

/**klasa pochodna figury opisująca sferę (kulę)*/
class Sphere: public GeometricObject {

    public:

        /**konstruktor klasy Sphere tworzący kulę o konkretnym promieniu, środku i kolorze*/
        Sphere(Vector3 newCenter, double newRadius, QColor newColor);
        /**funkcja sprawdzająca czy promień trafił w seferę*/
        bool const HitTest(VRay ray, double &minDistance);

    private:

    /**zmienna określająca środek kuli*/
    Vector3 center;
    /**zmienna określająca promień kuli*/
    double radius;

};

#endif
