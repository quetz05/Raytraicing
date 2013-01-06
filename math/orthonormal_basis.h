#ifndef ORTHONORMAL_BASIS_H
#define ORTHONORMAL_BASIS_H
#include"../vector.h"
/**
    klasa reprezentująca bazę ortonormalną urzywane wszędzie gdzie potrzebujemy lokalnego układu wspołrzędnych
*/
class OrthonormalBasis{
public:
    /** domyślny konstruktor bazy ortonormalnej przyjmujący
    wektor początku układu współrzędnych i dwa wektory na ktorych konstruujemy baze
 */
    OrthonormalBasis(Vector3 eye,Vector3 lookAt, Vector3 up);
    /**
    operator mnożenia bazy przez wektor
    */
    Vector3 operator*(Vector3 v);
private:
    Vector3 u;
    Vector3 v;
    Vector3 w;

};

#endif // ORTHONORMAL_BASIS_H
