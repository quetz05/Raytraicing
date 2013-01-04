/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#include "ray.h"
#include "vector.h"
#include <QColor>

/**klasa bazowa figury geometrycznej*/
class Geometric_object {

    public:

        /**funkcja sprawdzająca trafienie promienia w figurę*/
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
class Sphere: Geometric_object {

    public:

        /**konstruktor klasy Sphere tworzący kulę o konkretnym promieniu, środku i kolorze*/
        Sphere(Vector3 newCenter, double newRadius, QColor newColor);
        /**funkcja sprawdzająca trafienie promienia w figurę*/
        bool const HitTest(VRay ray, double &minDistance);

    private:

    /**zmienna określająca środek kuli*/
    Vector3 center;
    /**zmienna określająca promień kuli*/
    double radius;

};
