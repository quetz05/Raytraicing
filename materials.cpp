#include "materials.h"
#include<QColor>
#include "hit_info.h"


/**przeciążona metoda tworząca blask materiału*/
QColor PerfectDiffuse::radiance(PointLight light, const HitInfo &hit){

    //wektor kierunkowy
    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    //współczynnik rozpraszania
    double diffuse_factor = in_direction.dot(hit.normal);

    //jeśli współczynnik rozpraszania < 0 - zwróć czarny
    if (diffuse_factor < 0)
        return QColor(0,0,0);



    //radiancja jako iloczyn 3 składowych: koloru światła, koloru materiału i współczynnika rozproszenia
    return light.get_color().rgb() * color.rgb()* diffuse_factor;

}

