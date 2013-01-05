#ifndef MATERIAL_H
#define MATERIAL_H

#include <QColor>
#include <hit_info.h>
#include <point_light.h>

/**klasa abstrakcyjna opisująca materiał*/
class Material{

    /**metoda tworząca blask materiału*/
    virtual QColor radiance(PointLight, HitInfo);

};

#endif // MATERIAL_H

