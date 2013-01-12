/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#ifndef GEO_OBJECTS
#define GEO_OBJECTS

#include "ray.h"
#include <QColor>
#include "materials.h"
#include "mycolor.h"

/**abstrakcyjna klasa bazowa figury geometrycznej*/
class GeometricObject{

    public:

        /**funkcja sprawdzająca czy dany promień trafił w figurę (na podstawie odległości i normalnej)*/
        virtual bool hit_test(VRay ray, double &distance, Vector3 &normal)=0;
        /**funkcja zwracająca materiał z jakiego wykonana jest figura*/
        Material *get_material();
        /**wirtualny destruktor klasy*/
        virtual ~GeometricObject(){delete material;}

    protected:

        /**materiał z jakiego figura jest wykonana*/
        Material *material;
};

/**klasa pochodna figury opisująca sferę (kulę)*/
class Sphere: public GeometricObject{

    public:

        /**konstruktor klasy Sphere tworzący kulę o konkretnym promieniu, środku i materiale wykonania*/
        Sphere(Vector3 n_center, double n_radius, Material * n_material);
        /**przeciążona funkcja sprawdzająca czy promień trafił w seferę*/
        bool hit_test(VRay ray, double &distance, Vector3 &normal);

    private:

        /**zmienna określająca położenie środka kuli*/
        Vector3 center;
        /**zmienna określająca długość promienia kuli*/
        double radius;

};

/**klasa pochodna figury opisująca płaszczyznę*/
class Plane: public GeometricObject {

    public:
        /**konstruktor tworzący płaszczyznę przechodzącą przez dany punkt, mającą daną normalną i wyknaną z danego materiału*/
        Plane(Vector3 n_point, Vector3 n_normal, Material * n_material);
        /**funkcja sprawdzająca czy promień trafił w płaszczyznę*/
        bool  hit_test(VRay ray, double &min_distance, Vector3 &out_normal);


    private:
        /**punkt, przez który przechodzi płaszczyzna*/
        Vector3 point;
        /**normalna do płaszczyzny*/
        Vector3 normal;

};


/**klasa pochodna figury opisująca sześcian*/
class Cube: public GeometricObject {

    public:
        /**funkcja sprawdzająca czy promień trafił w sześcian*/
        bool  hit_test(VRay ray, double &min_distance, Vector3 &normal);


    private:

};

#endif
