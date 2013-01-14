/**nagłówek z klasami wektora trójwymiarowego i dwuwymiarowego*/
#ifndef VECTOR3D
#define VECTOR3D
#include <math.h>

/** @brief Vector3 klasa wektora trójwymiarowego*/
class Vector3{

    public:

        /** @brief Vector3 kontruktor bezargumentowy (tworzy wektor [0,0,0])*/
        Vector3(){x=0;y=0;z=0;}
        /** @brief Vector3 kontruktor tworzący wektor trójwymiarowy o określonych współrzędnych [a,b,c]*/
        Vector3(double a,double b,double c){ x=a; y=b; z=c;}
        /** @brief Vector3 kontruktor kopiujący wektor trójwymiarowy*/
        Vector3(const Vector3 &v): x(v.x),y(v.y),z(v.z){}

        /** @brief operator + przeciążenie operatora dodawania dwóch wektorów trójwymiarowych*/
        Vector3 operator +(const Vector3 &vector){return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z );}
        /** @brief operator - przeciążenie operatora odejmowania dwóch wektorów trójwymiarowych*/
        Vector3 operator -(const Vector3 &vector){return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z );}
        /** @brief operator * przeciążenie operatora mnożenia przez skalar wektorów trójwymiarowych*/
        Vector3 operator *(double value){return Vector3(this->x *value, this->y *value, this->z *value);}
        /** @brief operator / przeciążenie operatora dzielenia przez skalar dwóch wektorów trójwymiarowych*/
        Vector3 operator /(double value){return Vector3(this->x /value, this->y /value, this->z /value);}
        /** @brief operator = przeciążenie operatora przypisania dla wektorów trójwymiarowych*/
        Vector3& operator =(Vector3 const &vector);
        /** @brief operator == przeciążenie operatora porówniania dwóch wektorów trójwymiarowych*/
        bool operator ==(const Vector3 &vector);


        /** @brief dot funkcja zwracająca iloczyn skalarny dwóch wektorów trójwymiarowych*/
        double dot(Vector3 vector){return (this->x * vector.x + this->y * vector.y + this->z * vector.z);}
        /** @brief cross funkcja zwracająca iloczyn wektorowy dwóch wektorów trójwymiarowych*/
        Vector3 cross(Vector3 vector){return Vector3(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);}


        /** @brief get_length() funkcja zwracająca długość wektora trójwymiarowego*/
        double get_length(){return sqrt(x*x+y*y+z*z);}
        /** @brief get_length_sq() funkcja zwracająca długość podniesioną do kwadratu wektora trójwymiarowego*/
        double get_length_sq(){return x*x+y*y+z*z;}
        /** @brief normalized() funkcja zwracająca znormalizowany wektor trójwymiarowy*/
        Vector3 normalized(){return (*this)/(this->get_length());}
        /** @brief reflect funkcja odbicia wektora od nromalnej, wyzaczająca wektro odbity*/
        static Vector3 reflect(Vector3 vector, Vector3 normal);
        /** @brief contrary funkcja tworząca wektor przeciwny do danego*/
        static Vector3 contrary(Vector3 vector);


        /** @brief getX() funkcja zwracająca współrzędną x wektora trójwymiarowego*/
        double getX(){return x;}
        /** @brief getY() funkcja zwracająca współrzędną y wektora trójwymiarowego*/
        double getY(){return y;}
        /** @brief getZ() funkcja zwracająca współrzędną z wektora trójwymiarowego*/
        double getZ(){return z;}
        /** @brief setX funkcja ustalająca współrzędną x wektora trójwymiarowego*/
        void setX(double i) {x = i;}
        /** @brief setY funkcja ustalająca współrzędną y wektora trójwymiarowego*/
        void setY(double i) {y = i;}
        /** @brief setZ funkcja ustalająca współrzędną z wektora trójwymiarowego*/
        void setZ(double i) {z = i;}

    private:

        /** @brief x współrzędna x wektora trójwymiarowego*/
        double x;
        /** @brief y współrzędna y wektora trójwymiarowego*/
        double y;
        /** @brief z współrzędna z wektora trójwymiarowego*/
        double z;

};

/** @brief Vector2 struktura wektora dwuwymiarowego*/
struct Vector2{

    /** @brief Vector2 kontruktor tworzący wektor o współrzędnych [a,b]*/
    inline Vector2(double a, double b){x=a;y=b;}
    /** @brief Vector2 kontruktor bezargumentowy (tworzy wektor [0,0])*/
    inline Vector2(): x(0),y(0){}
    /** @brief operator* przeciążenie operatora mnożenia wektora dwywymiarowego przez wartość*/
    Vector2 operator*(double val){return Vector2(x*val,y*val);}
    /** @brief operator/ przeciążenie operatora dzielenia wektora dwywymiarowego przez wartość*/
    Vector2 operator/(double val){return Vector2(x/val,y/val);}



    /** @brief x współrzędna x wektora dwuwymiarowego*/
    double x;
    /** @brief y współrzędna y wektora dwuwymiarowego*/
    double y;
};

#endif
