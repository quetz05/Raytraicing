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
    Vector3 distance = ray.origin - center;

    double a = ray.direction.getLengthSq();
    double b = (distance * 2).dot(ray.direction);
    double c = distance.getLengthSq() - radius * radius;

    double disc = b * b - 4 * a * c;

    if (disc < 0)
        return false;

    double discSq = sqrt(disc);

    double denom = 2 * a;

    t = (-b - discSq) / denom;

    if (t < EPSILON)
        t = (-b + discSq) / denom;

    if (t < EPSILON)
        return false;

    minDistance = t;

    return true;
}

