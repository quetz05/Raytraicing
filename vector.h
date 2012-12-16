#include <math.h>

#ifndef VECTOR3D
#define VECTOR3D
//klasa wektor
class Vector3{

    public:

    //konstruktor
    Vector3(double a,double b,double c){ x=a; y=b; z=c;};


    //przeciazenia operatorow
    Vector3 operator +(const Vector3 &vector){return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z );};
    Vector3 operator -(const Vector3 &vector){return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z );};
    Vector3 operator *(double value){return Vector3(this->x *value, this->y *value, this->z *value);};
    Vector3 operator /(double value){return Vector3(this->x /value, this->y /value, this->z /value);};
    Vector3 &operator =(const Vector3 &vector);
    bool operator ==(const Vector3 &vector);


    //iloczyn skalarny:
    double dot(Vector3 vector){return (this->x * vector.x + this->y * vector.y + this->z * vector.z);};
    //iloczyn wektorowy:
    Vector3 cross(Vector3 vector){return Vector3(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);}


    //zwroc dlugosc wektora
    double getLength(){return sqrt(x*x+y*y+z*z);};
    //zwroc pierwiatek dlugosci wektora
    double getLengthSq(){return x*x+y*y+z*z;};
    //normalizacja wektora
    Vector3 normalized(){return (*this)/(this->getLength());};



    //metody do zwracania wspolrzednych wektora
    double getX(){return x;};
    double getY(){return y;};
    double getZ(){return z;};
    //metody do ustawiania wspolrzednych wektora
    void setX(double i) {x = i;};
    void setY(double i) {y = i;};
    void setZ(double i) {z = i;};

    private:

    double x;
    double y;
    double z;

};

Vector3 &Vector3::operator =(const Vector3 &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;

    return *this;
};

bool Vector3::operator ==(const Vector3 &vector)
{
    if(( this->x == vector.x ) &&( this->y == vector.y ) && (this->z == vector.z) )
         return true;
    else
         return false;

};

#endif
