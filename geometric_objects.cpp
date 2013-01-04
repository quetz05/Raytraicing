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

    //rozwiązanie równania kwadratowego
    double t;
    //dystans początku promienia od środka sfery
    Vector3 distance = ray.origin - center;

    //obliczanie współczynników równania kwadratowego
    //na podstawie przekształceń równań na promień i na kulę
    double a = ray.direction.getLengthSq();
    double b = (distance*2).dot(ray.direction);
    double c = distance.getLengthSq() - radius*radius;

    //obliczenie delty
    double delta = b*b-4*a*c;

    //jeśli delta < 0 - promień nie trafił w kulę
    if (delta < 0)
        return false;

    //pierwiastek z delty
    double deltaSq = sqrt(delta);

    //obliczanie t1
    t = (-b - deltaSq)/(2*a);

    //jeśli t1 jest zbyt małe obliczanie t2
    if (t < EPSILON)
        t = (-b + deltaSq)/(2*a);

    //jeśli oba rozwiązania są zbyt małe - promień nie trafił w kulę
    if (t < EPSILON)
        return false;

    //przypisanie wartości rozwiązania do minimalnej odległości
    minDistance = t;

    return true;
}

