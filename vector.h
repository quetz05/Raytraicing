/**nagłówek z klasą wektora trójwymiarowego i dwuwymiarowego*/


#ifndef VECTOR3D
#define VECTOR3D

#include <math.h>
/**klasa wektora trójwymiarowego*/
class Vector3{

    public:

        /**kontruktor bezargumentowy (tworzy wektor [0,0,0])*/
        Vector3(){x=0;y=0;z=0;}
        /**kontruktor tworzący wektor trójwymiarowy o określonych współrzędnych*/
        Vector3(double a,double b,double c){ x=a; y=b; z=c;}
        /**kontruktor kopiujący*/
        Vector3(const Vector3 &v): x(v.x),y(v.y),z(v.z){}

        /**przeciążenie operatora dodawania dwóch wektorów trójwymiarowych*/
        Vector3 operator +(const Vector3 &vector){return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z );}
        /**przeciążenie operatora odejmowania dwóch wektorów trójwymiarowych*/
        Vector3 operator -(const Vector3 &vector){return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z );}
        /**przeciążenie operatora mnożenia przez skalar wektorów trójwymiarowych*/
        Vector3 operator *(double value){return Vector3(this->x *value, this->y *value, this->z *value);}
        /**przeciążenie operatora dzielenia przez skalar dwóch wektorów trójwymiarowych*/
        Vector3 operator /(double value){return Vector3(this->x /value, this->y /value, this->z /value);}
        /**przeciążenie operatora przypisania dla wektorów trójwymiarowych*/
        Vector3& operator =( Vector3 const &vector);
        /**przeciążenie operatora porówniania dwóch wektorów trójwymiarowych*/
        bool operator ==(const Vector3 &vector);


        /**funkcja zwracająca iloczyn skalarny dwóch wektorów trójwymiarowych*/
        double dot(Vector3 vector){return (this->x * vector.x + this->y * vector.y + this->z * vector.z);}
        /**funkcja zwracająca iloczyn wektorowy dwóch wektorów trójwymiarowych*/
        Vector3 cross(Vector3 vector){return Vector3(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);}


        /**funkcja zwracająca długość wektora trójwymiarowego*/
        double getLength(){return sqrt(x*x+y*y+z*z);}
        /**funkcja zwracająca długość podniesioną do kwadratu wektora trójwymiarowego*/
        double getLengthSq(){return x*x+y*y+z*z;}
        /**funkcja zwracająca znormalizowany wektor trójwymiarowy*/
        Vector3 normalized(){return (*this)/(this->getLength());}
        /**funkcja odbicia, potrzebna do modelu Phonga*/
        Vector3 reflect(Vector3 vec, Vector3 normal);



        /**funkcja zwracająca współrzędną x wektora trójwymiarowego*/
        double getX(){return x;}
        /**funkcja zwracająca współrzędną y wektora trójwymiarowego*/
        double getY(){return y;}
        /**funkcja zwracająca współrzędną z wektora trójwymiarowego*/
        double getZ(){return z;}
        /**funkcja ustalająca współrzędną x wektora trójwymiarowego*/
        void setX(double i) {x = i;}
        /**funkcja ustalająca współrzędną y wektora trójwymiarowego*/
        void setY(double i) {y = i;}
        /**funkcja ustalająca współrzędną z wektora trójwymiarowego*/
        void setZ(double i) {z = i;}

        private:

            /**współrzędna x wektora trójwymiarowego*/
            double x;
            /**współrzędna y wektora trójwymiarowego*/
            double y;
            /**współrzędna z wektora trójwymiarowego*/
            double z;

};

/**struktura wektora dwuwymiarowego*/
struct Vector2{

    /**współrzędna x wektora dwuwymiarowego*/
	double x;
    /**współrzędna y wektora dwuwymiarowego*/
	double y;
    Vector2 operator*(double val){return Vector2(x*val,y*val);}
    Vector2 operator/(double val){return Vector2(x/val,y/val);}
    /**kontruktor tworzący wektor dwuwymiarowy o określonych współrzędnych*/
    inline Vector2(double a, double b){x=a;y=b;}
    /**kontruktor bezargumentowy (tworzy wektor [0,0])*/
    inline Vector2(): x(0),y(0){}
};

#endif
