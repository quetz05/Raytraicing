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
/**deklaracja klasy VRay*/
class VRay;

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
        /**konstruktor klasy tworzący materiał Phonga o konkretnych parametrach*/
        Phong(MyColor, double, double, double);
        /**przeciążona metoda tworząca blask materiału Phonga*/
        MyColor radiance(const PointLight, HitInfo&);
        /**metoda wyliczająca współczynnik Phonga*/
        double phong_factor(Vector3, Vector3 , Vector3);
        /**przeciążona metoda tworząca cień materiału Phonga*/
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

        /**konstruktor klasy tworzący materiał modelujący odbicie o danych parametrach*/
        Reflective(MyColor, double, double,double, double);
        /**przeciążona metoda tworząca blask materiału modelującego odbicie*/
        MyColor radiance(const PointLight, HitInfo &);
        /**przeciążona metoda tworząca cień materiału modelującego odbicie*/
        MyColor shade(Raytracer &tracer, HitInfo &hit);

    private:
             double reflectivity;
             Phong direct;
};

/**klasa reprezentująca materiał przezroczysty (uproszczony)*/
class Transparent : public Material
{

    public:

        /**konstruktor tworzący materiał przezroczysty o konkretnych parametrach*/
        Transparent(MyColor, double, double,double, double, double , double);
        /**przeciążona metoda tworząca cień materiału przezroczystego*/
        MyColor shade(Raytracer &tracer, HitInfo &hit);
        /**przeciążona metoda tworząca blask materiału przezroczystego*/
        MyColor radiance(const PointLight, HitInfo &){return MyColor(1,1,1);};

        MyColor compute_transmission_color(double);

        double find_refraction_coeff(double, double);

        bool is_total_internal_reflection(double);

        VRay compute_transmission_direction(Vector3, Vector3, Vector3, double, double, double);

    private:

        Phong direct;
        double refraction;
        double reflection;
        double transmission;
        double specular;
};



#endif // MATERIAL_H

