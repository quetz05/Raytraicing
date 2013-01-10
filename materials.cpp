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

    QColor ret ((light.get_color().red()*color.red()*diffuse_factor)/255,
                (light.get_color().green()*color.green()*diffuse_factor)/255,
                (light.get_color().blue()*color.blue()*diffuse_factor)/255);


    //radiancja jako iloczyn 3 składowych: koloru światła, koloru materiału i współczynnika rozproszenia
    return ret;

}

Phong::Phong(QColor n_color, double n_diffuse, double n_specular,double n_specular_e){
     color = n_color;
     diffuse_coeff = n_diffuse;
     specular = n_specular;
     specular_exponent = n_specular_e;
}

/**NIEDOKOŃĆZONA!!*/
QColor Phong::radiance(PointLight light,const HitInfo& hit){

    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    double diffuse_factor = in_direction.dot(hit.normal);

    if (diffuse_factor < 0)
        return QColor(0,0,0);


    QColor result = QColor(0,0,0);//QColor( light.get_color().rgb() * color * diffuse_factor * diffuse_coeff);

    /*double phong_factor;// = phong_factor(inDirection, hit.normal, -hit.Ray.Direction);

    if (phong_factor != 0)
        result += materialColor * specular * phongFactor;*/

    return result;



}
