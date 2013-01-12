/**nagłówek zawierający deklarację klas i funkcji związanych z materiałem*/
#ifndef MATERIAL_H
#define MATERIAL_H
#include <QColor>
#include "point_light.h"
#include "mycolor.h"

/**deklaracja klasy HitInfo*/
class HitInfo;
/**deklaracja klasy World*/
class Raytracer;

/**klasa abstrakcyjna opisująca materiał*/
class Material{
    public:

        /**metoda wirtualna tworząca blask materiału*/
        virtual MyColor radiance(const PointLight, HitInfo&)=0;
        /**metoda wirtualna tworząca cień materiału*/
        virtual MyColor shade(Raytracer &tracer, HitInfo &hit)=0;

    protected:

        /**kolor materiału*/
        MyColor color;

};

/**klasa reprezentująca materiał idealnie rozpraszający*/
class PerfectDiffuse: public Material{

    public:

        /**konstruktor tworzący materiał danego koloru*/
        PerfectDiffuse(MyColor c){color=c;}
        /**przeciążona metoda tworząca blask materiału idealnie rozpraszającego*/
        MyColor radiance(const PointLight, HitInfo &);
        /**przeciążona metoda tworząca cień materiału idealnie rozpraszającego*/
        MyColor shade(Raytracer &tracer, HitInfo &hit);


};

/**klasa reprezentująca materiał Phonga*/
class Phong : public Material{

    public:

        /**konstruktor klasy bezargumentowy (przypisujący polom obiektu wartości 0)*/
        Phong();
        /**konstruktor klasy tworzący materiał)*/
        Phong(MyColor, double, double, double);
        MyColor radiance(const PointLight, HitInfo&);
        double phong_factor(Vector3, Vector3 , Vector3);

        MyColor shade(Raytracer &tracer, HitInfo &hit);

         private:

             /**współczynnik dyfuzji*/
             double diffuse_coeff;
             /**rozbłysk*/
             double specular;
             /**wykładnik rozbłysku*/
             double specular_exponent;
};


/**klasa reprezentująca materiał modelujący odbicie*/
class Reflective : public Material{

    public:

        /**konstruktor klasy*/
        Reflective(MyColor, double, double,double, double);
        MyColor radiance(const PointLight, HitInfo &);

        MyColor shade(Raytracer &tracer, HitInfo &hit);

         private:
             /**kolor materiału*/
            // MyColor color;
             double reflectivity;
             Phong direct;
};




#endif // MATERIAL_H

