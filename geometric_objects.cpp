/**Plik źródłowy zawierający definicje funkcji klas obiektów geometrycznych*/

#include "geometric_objects.h"

/**definicja funkcji getColor obiektu*/
QColor Geometric_object::getColor(){
    return color;
}

/**definicja funkcji setColor obiektu*/
void Geometric_object::setColor(QColor newColor){
    color = newColor;
}

/**definicja konstruktora klasy Sphere (Kuli)*/
Sphere::Sphere(Vector3 newCenter, double newRadius, QColor newColor){
    center = newCenter;
    radius = newRadius;
    color = newColor;
}

/**definicja funkcji HitTest*/
bool const Sphere::HitTest(VRay ray, double &minDistance){

    double t;
    Vector3 distance = ray.Origin - center;

    double a = ray.Direction.LengthSq;
    double b = (distance * 2).Dot(ray.Direction);
    double c = distance.LengthSq - radius * radius;

    double disc = b * b - 4 * a * c;

    if (disc < 0)
        return false;

    double discSq = Math.Sqrt(disc);

    double denom = 2 * a;

    t = (-b - discSq) / denom;

    if (t < Ray.Epsilon)
        t = (-b + discSq) / denom;

    if (t < Ray.Epsilon)
        return false;

    minDistance = t;

    return true;
}

