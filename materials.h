#ifndef MATERIAL_H
#define MATERIAL_H

#include <QColor>
#include "point_light.h"

class HitInfo;

/**klasa abstrakcyjna opisująca materiał*/
class Material{
public:

    /**metoda tworząca blask materiału*/
    virtual QColor radiance(PointLight, const HitInfo&)=0;

};

/**klasa reprezentująca materiał idealnie rozpraszający*/
class PerfectDiffuse: public Material{

    public:

        /**konstruktor tworzący materiał danego koloru*/
        PerfectDiffuse(QColor c): color(c){}
        /**przeciążona metoda tworząca blask materiału*/
        QColor radiance(PointLight, const HitInfo &);



    private:

        /**kolor materiału*/
        QColor color;

};

/**klasa reprezentująca materiał Phonga*/
class Phong : public Material{

    public:

        /**konstruktor klasy*/
        Phong(QColor, double, double,double);
        QColor radiance(PointLight light,const HitInfo&);

         private:
             /**kolor materiału*/
             QColor color;
             double diffuse_coeff;
             double specular;
             double specular_exponent;
};


#endif // MATERIAL_H

