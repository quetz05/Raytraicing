#ifndef MATERIAL_H
#define MATERIAL_H

#include <QColor>
#include "point_light.h"
#include "mycolor.h"

class HitInfo;

/**klasa abstrakcyjna opisująca materiał*/
class Material{
public:

    /**metoda tworząca blask materiału*/
    virtual MyColor radiance(PointLight, const HitInfo&)=0;

};

/**klasa reprezentująca materiał idealnie rozpraszający*/
class PerfectDiffuse: public Material{

    public:

        /**konstruktor tworzący materiał danego koloru*/
        PerfectDiffuse(MyColor c): color(c){}
        /**przeciążona metoda tworząca blask materiału*/
        MyColor radiance(PointLight, const HitInfo &);



    private:

        /**kolor materiału*/
        MyColor color;

};

/**klasa reprezentująca materiał Phonga*/
class Phong : public Material{

    public:

        /**konstruktor klasy*/
        Phong(MyColor, double, double,double);
        MyColor radiance(PointLight light,const HitInfo&);
        double phong_factor(Vector3, Vector3 , Vector3);

         private:
             /**kolor materiału*/
             MyColor color;
             double diffuse_coeff;
             double specular;
             double specular_exponent;
};


#endif // MATERIAL_H

