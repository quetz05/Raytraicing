#include "materials.h"
#include<QColor>
#include "hit_info.h"
#include <math.h>


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
MyColor PerfectDiffuse::radiance(PointLight light, const HitInfo &hit){

    //wektor kierunkowy
    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    //współczynnik rozpraszania
    double diffuse_factor = in_direction.dot(hit.normal);

    //jeśli współczynnik rozpraszania < 0 - zwróć czarny
    if (diffuse_factor < 0)
        return MyColor(0,0,0);

    //radiancja jako iloczyn 3 składowych: koloru światła, koloru materiału i współczynnika rozproszenia
    MyColor final = light.get_color()* color* diffuse_factor;



    return final;

}

Phong::Phong(MyColor n_color, double n_diffuse, double n_specular,double n_specular_e){
     color = n_color;
     diffuse_coeff = n_diffuse;
     specular = n_specular;
     specular_exponent = n_specular_e;
}

/**definicja metody radiance materiału Phonga*/
MyColor Phong::radiance(PointLight light,const HitInfo& hit){

    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    double diffuse_factor = in_direction.dot(hit.normal);

    if (diffuse_factor < 0)
        return MyColor(0,0,0);

    double multiply = diffuse_factor * diffuse_coeff;

    MyColor result = light.get_color()* color* multiply;

    double phong;

    phong = phong_factor(in_direction, hit.normal, Vector3::contrary(hit.ray.direction));

    if (phong != 0){

        result = result + light.get_color() * phong*specular;
    }

    return result;

}





