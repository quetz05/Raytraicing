/**Plik źródłowy zawierający definicję niektórych metod klasy Vector3 */
#include"vector.h"


Vector3 &Vector3::operator =(const Vector3 &vector){

    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;

    return *this;
}


bool Vector3::operator ==( Vector3 const &vector){

    if((this->x == vector.x) &&(this->y == vector.y) && (this->z == vector.z))
         return true;
    else
         return false;

}


Vector3 Vector3::reflect(Vector3 vector, Vector3 normal){

    double dot = normal.dot(vector);
    return normal*dot*2 - vector;
}


Vector3 Vector3::contrary(Vector3 vector){
    double x= -(vector.getX());
    double y= -(vector.getY());
    double z= -(vector.getZ());

    Vector3 ret(x,y,z);
    return ret;
}
