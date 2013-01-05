/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#ifndef GEO_OBJECTS
#define GEO_OBJECTS

#include "ray.h"
#include <QColor>


/**klasa bazowa figury geometrycznej*/
class GeometricObject {

    public:

        /**funkcja sprawdzająca czy promień trafił w figurę*/
        virtual bool const hit_test(VRay ray, double &distance);
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
        bool const hit_test(VRay ray, double &distance);

    private:

    /**zmienna określająca środek kuli*/
    Vector3 center;
    /**zmienna określająca promień kuli*/
    double radius;

};

/**klasa pochodna figury opisująca płaszczyznę*/
class Plane: public GeometricObject {

    public:
    /**konstruktor płaszczyzny*/
    Plane(Vector3 n_point, Vector3 n_normal, QColor n_color);
    /**funkcja sprawdzająca czy promień trafił w płaszczyznę*/
    bool const hit_test(VRay ray, double &min_distance);



    private:
    /**punkt, przez który przechodzi płaszczyzna*/
    Vector3 point;
    /**normalna do płaszczyzny*/
    Vector3 normal;


};

#endif
