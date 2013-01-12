/**Plik źródłowy zawierający definicje funkcji klas obiektów geometrycznych*/
#include "geometric_objects.h"


/**definicja metody get_material*/
Material *GeometricObject::get_material(){
    return material;
}


/**definicja konstruktora klasy Sphere (Kuli)*/
Sphere::Sphere(Vector3 n_center, double n_radius, Material * n_material){
    center = n_center;
    radius = n_radius;
    material = n_material;
}

/**definicja funkcji hit_test dla sfery*/
bool  Sphere::hit_test(VRay ray, double &min_distance, Vector3 &normal){

    //rozwiązanie równania kwadratowego
    double t;
    //dystans początku promienia od środka sfery
    Vector3 distance = ray.origin - center;

    //obliczanie współczynników równania kwadratowego
    //na podstawie przekształceń równań na promień i na kulę
    double a = ray.direction.get_length_sq();
    double b = (distance*2).dot(ray.direction);
    double c = distance.get_length_sq() - radius*radius;

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

    Vector3 hit_point = (ray.origin + ray.direction * t);
    normal = (hit_point - center).normalized();
    //przypisanie wartości rozwiązania do minimalnej odległości
    min_distance = t;

    return true;
}

/**definicja konstruktora płaszczyzny*/
Plane::Plane(Vector3 n_point, Vector3 n_normal, Material * n_material){

    point = n_point;
    normal = n_normal;
    material = n_material;
}

/**definicja medody hit_test dla płaszczyzny*/
bool Plane::hit_test(VRay ray, double &distance, Vector3 &out_normal){

    //równanie wynikające z podstawienia równania prostej do równania płaszczyzny
    double x = (point - ray.origin).dot(normal)/(ray.direction.dot(normal));

    //jeśli x większy od EPSILON - promień trafił
    if(x>EPSILON){

        distance = x;
        out_normal=normal;
        return true;
    }

    return false;
}

