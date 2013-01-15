/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#ifndef GEO_OBJECTS
#define GEO_OBJECTS

#include "ray.h"
#include <QColor>
#include "materials.h"
#include "mycolor.h"

/**
 * @brief GeometricObject abstrakcyjna klasa bazowa figury geometrycznej
 */
class GeometricObject{

    public:

        /**
         * @brief hit_test funkcja sprawdzająca czy dany promień trafił w figurę
         * @param ray promień
         * @param distance odległość
         * @param normlal normalna
         * @return wartość true/false zależnie czy promień trafił w figurę
         */
        virtual bool hit_test(VRay ray, double &distance, Vector3 &normal)=0;
        /**
         * @brief get_material funkcja zwracająca materiał z jakiego wykonana jest figura
         * @return typ materiału figury
         */
        Material *get_material();
        /**
         * @brief ~GeometricObject wirtualny destruktor klasy
         */
        virtual ~GeometricObject(){delete material;}

    protected:

        /**
         * @brief material materiał z jakiego figura jest wykonana
         */
        Material *material;
};

/**
 * @brief Sphere klasa opisująca kulę
 */
class Sphere: public GeometricObject{

    public:

        /**
         * @brief Sphere konstruktor sfery
         * @param n_center środek kuli
         * @param n_radius długość promienia kuli
         * @param n_material typ materiału z jakiego kula jest wykonana
         */
        Sphere(Vector3 n_center, double n_radius, Material * n_material);
        /**
         * @brief hit_test funkcja sprawdzająca czy dany promień trafił w sferę
         * @param ray promień
         * @param distance odległość
         * @param normlal normalna
         * @return wartość true/false zależnie czy promień trafił w sferę
         */
        bool hit_test(VRay ray, double &distance, Vector3 &normal);

    private:

        /**
         * @brief center środek kuli
         */
        Vector3 center;
        /**
         * @brief radius długość promienia kuli
         */
        double radius;

};

/**
 * @brief Plane klasa opisująca płaszczyznę
 */
class Plane: public GeometricObject {

    public:
        /**
         * @brief Plane konstruktor płaszczyzny
         * @param n_point punkt przez który przechodzi płaszczyzna
         * @param n_normal normalna płaszczyzny
         * @param n_material typ materiału z jakiego płaszczyzna jest wykonana
         */
        Plane(Vector3 n_point, Vector3 n_normal, Material * n_material);
        /**
         * @brief hit_test funkcja sprawdzająca czy dany promień trafił w płaszczyznę
         * @param ray promień
         * @param distance odległość
         * @param normlal normalna
         * @return wartość true/false zależnie czy promień trafił w płaszczyznę
         */
        bool  hit_test(VRay ray, double &min_distance, Vector3 &out_normal);


    private:
        /**
         * @brief point punkt przez który przechodzi płaszczyzna
         */
        Vector3 point;
        /**
         * @brief normal normalna płaszczyzny
         */
        Vector3 normal;

};


#endif
