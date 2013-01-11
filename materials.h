#ifndef MATERIAL_H
#define MATERIAL_H
#include <QColor>
#include "point_light.h"
#include "mycolor.h"

class HitInfo;
class Raytracer;

/**klasa abstrakcyjna opisujÄ…ca materiaĹ‚*/
class Material{
public:

    /**metoda tworzÄ…ca blask materiaĹ‚u*/
    virtual MyColor radiance(PointLight,  HitInfo&)=0;
    virtual MyColor shade( Raytracer &tracer, HitInfo &hit)=0;

};

/**klasa reprezentujÄ…ca materiaĹ‚ idealnie rozpraszajÄ…cy*/
class PerfectDiffuse: public Material{

    public:

        /**konstruktor tworzÄ…cy materiaĹ‚ danego koloru*/
        PerfectDiffuse(MyColor c): color(c){}
        /**przeciÄ…ĹĽona metoda tworzÄ…ca blask materiaĹ‚u*/
        MyColor radiance(PointLight, HitInfo &);

        MyColor shade(Raytracer &tracer, HitInfo &hit);



    private:

        /**kolor materiaĹ‚u*/
        MyColor color;

};

/**klasa reprezentujÄ…ca materiaĹ‚ Phonga*/
class Phong : public Material{

    public:

        /**konstruktor klasy*/
        Phong();
        Phong(MyColor, double, double,double);
        MyColor radiance(PointLight light, HitInfo&);
        double phong_factor(Vector3, Vector3 , Vector3);

        MyColor shade(Raytracer &tracer, HitInfo &hit);

         private:
             /**kolor materiaĹ‚u*/
             MyColor color;
             double diffuse_coeff;
             double specular;
             double specular_exponent;
};


/**klasa reprezentujÄ…ca materiaĹ‚ modelujÄ…cy odbicie*/
class Reflective : public Material{

    public:

        /**konstruktor klasy*/
        Reflective(MyColor, double, double,double, double);
        MyColor radiance(PointLight light, HitInfo &);

        MyColor shade(Raytracer &tracer, HitInfo &hit);

         private:
             /**kolor materiaĹ‚u*/
             MyColor color;
             double reflectivity;
             Phong direct;
};




#endif // MATERIAL_H

