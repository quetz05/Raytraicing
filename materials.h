#ifndef MATERIAL_H
#define MATERIAL_H

#include <QColor>
#include "hit_info.h"
#include "point_light.h"

/**klasa abstrakcyjna opisująca materiał*/
class Material{
public:
    Material(){}
    /**metoda tworząca blask materiału*/
    virtual QColor radiance(PointLight, HitInfo);

};

/**klasa reprezentująca materiał idealnie rozpraszający*/
class PerfectDiffuse: public Material{

    public:

        /**konstruktor tworzący materiał danego koloru*/
        PerfectDiffuse(QColor c): color(c){}
        /**przeciążona metoda tworząca blask materiału*/
        QColor radiance(PointLight, HitInfo);



    private:

        /**kolor materiału*/
        QColor color;

};


#endif // MATERIAL_H

