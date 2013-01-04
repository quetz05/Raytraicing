/**nagłówek zawierający deklaracje klas figur geoemtrycznych oraz ich metod i zmiennych*/
#include "ray.h"
#include "vector.h"
#include <QColor>

/**klasa bazowa figury geometrycznej*/
class Geometric_object {

    public:

        /**funkcja sprawdzająca trafienie promienia w figurę*/
        virtual bool HitTest(VRay ray, double &distance);
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

        Sphere(Vector3 newCenter, double newRadius, QColor newColor);


    bool const HitTest(VRay ray, double &minDistance);

    private:

    /**środek kuli*/
    Vector3 center;
    /**promień*/
    double radius;

};
