/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#ifndef GEO_OBJECTS
#define GEO_OBJECTS

#include "ray.h"
#include <QColor>
#include "materials.h"
#include"mycolor.h"

/**klasa bazowa figury geometrycznej*/
class GeometricObject {

    public:

        /**funkcja sprawdzająca czy promień trafił w figurę*/
        virtual bool  hit_test(VRay ray, double &distance, Vector3 &normal);
        /**funkcja zwracająca kolor figury*/
        QColor getColor();
        /**funkcja ustawiająca kolor figury*/
        void setColor(QColor newColor);
        /**funkcja zwracająca materiał figury*/
        Material *get_material();

    protected:

        //kolor figury
        QColor color;
        //materiał
        Material *material;
};

/**klasa pochodna figury opisująca sferę (kulę)*/
class Sphere: public GeometricObject {

    public:

        /**konstruktor klasy Sphere tworzący kulę o konkretnym promieniu, środku i kolorze*/
        Sphere(Vector3 newCenter, double newRadius, Material * n_material);
        /**funkcja sprawdzająca czy promień trafił w seferę*/
        bool  hit_test(VRay ray, double &distance, Vector3 &normal);

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
    Plane(Vector3 n_point, Vector3 n_normal, Material * n_material);
    /**funkcja sprawdzająca czy promień trafił w płaszczyznę*/
    bool  hit_test(VRay ray, double &min_distance, Vector3 &out_normal);



    private:
    /**punkt, przez który przechodzi płaszczyzna*/
    Vector3 point;
    /**normalna do płaszczyzny*/
    Vector3 normal;


};

#endif
