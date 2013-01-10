#include"vector.h"
/**definicja przeciążenia operatora przypisania dla wektorów trójwymiarowych*/
Vector3 &Vector3::operator =(const Vector3 &vector){

    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;

    return *this;
}

/**definicja przeciążenia operatora porównania wektorów trójwymiarowych*/
bool Vector3::operator ==( Vector3 const &vector){

    if(( this->x == vector.x ) &&( this->y == vector.y ) && (this->z == vector.z) )
         return true;
    else
         return false;

}

/**definicja metody reflect*/
Vector3 reflect(Vector3 vector, Vector3 normal){

    double dot = normal.dot(vector);
    return 2*normal*dot - vec;
}
