/**Plik źródłowy zawierający definicje funkcji klas obiektów geometrycznych*/
#include "geometric_objects.h"

/**definicja funkcji getColor obiektu*/
QColor GeometricObject::getColor(){
    return color;
}

/**definicja funkcji setColor obiektu*/
void GeometricObject::setColor(QColor newColor){
    color = newColor;
}
/**definicja wirtualnej funkcji poniewaz czysto wirtualna nie da nam zrobić listy takich obiektów*/
bool  GeometricObject::hit_test(VRay ray, double &distance){
	return false;
}

/**definicja konstruktora klasy Sphere (Kuli)*/
Sphere::Sphere(Vector3 newCenter, double newRadius, QColor newColor){
    center = newCenter;
    radius = newRadius;
    color = newColor;
}

/**definicja funkcji HitTest*/
bool  Sphere::hit_test(VRay ray, double &min_distance){

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
    min_distance = t;

    return true;
}

/**deklaracja konstruktora płaszczyzny*/
Plane::Plane(Vector3 n_point, Vector3 n_normal, QColor n_color){

    point = n_point;
    normal = n_normal;
    color = n_color;
}

/**funkcja sprawdzająca czy promień trafił w płaszczyznę*/
bool Plane::hit_test(VRay ray, double &distance){

    //równanie wynikające z podstawienia równania prostej do równania płaszczyzny
    double x = (point - ray.origin).dot(normal)/(ray.direction.dot(normal));

    if(x>EPSILON){
        distance = x;
        return true;
    }

    return false;
}

