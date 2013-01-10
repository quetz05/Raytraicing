#include "materials.h"
#include<QColor>
#include "hit_info.h"
#include <math.h>

/**metoda wymnażająca dwa kolory*/
QColor multiply_colors (QColor c1, QColor c2){

    return QColor((c1.red()*c2.red())/255,(c1.green()*c2.green())/255,(c1.blue()*c2.blue())/255);

}

/**metoda wymnażająca kolor i liczbę*/
QColor multiply_color (QColor c1, double multiply){

    return QColor((c1.red()*multiply)/255,(c1.green()*multiply)/255,(c1.blue()*multiply)/255);

}

/**metoda licząca współczynnik Phonga*/
double Phong::phong_factor(Vector3 in_direction, Vector3 normal, Vector3 to_camera_direction)
{
    Vector3 reflected = Vector3::reflect(in_direction, normal);

    double cos_angle = reflected.dot(to_camera_direction);

    if (cos_angle <= 0)
        return 0;

    return pow(cos_angle, specular_exponent);
}


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

/**definicja metody radiance materiału Phonga*/
QColor Phong::radiance(PointLight light,const HitInfo& hit){

    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    double diffuse_factor = in_direction.dot(hit.normal);

    if (diffuse_factor < 0)
        return QColor(0,0,0);



    QRgb result = multiply_color(multiply_colors(light.get_color(), color), diffuse_factor * diffuse_coeff).rgb();

    double phong;

    phong = phong_factor(in_direction, hit.normal, Vector3::contrary(hit.ray.direction));

    if (phong != 0)
        result += multiply_color(color,  specular * phong).rgb();

    return QColor(result);

}





