#include "materials.h"
#include<QColor>
#include "hit_info.h"
#include <math.h>
#include "raytracer.h"




/**metoda liczÄ…ca wspĂłĹ‚czynnik Phonga*/
double Phong::phong_factor(Vector3 in_direction, Vector3 normal, Vector3 to_camera_direction)
{
    Vector3 reflected = Vector3::reflect(in_direction, normal);

    double cos_angle = reflected.dot(to_camera_direction);

    if (cos_angle <= 0)
        return 0;

    return pow(cos_angle, specular_exponent);
}


/**przeciÄ…ĹĽona metoda tworzÄ…ca blask materiaĹ‚u*/
MyColor PerfectDiffuse::radiance(PointLight light, HitInfo &hit){

    //wektor kierunkowy
    Vector3 in_direction = (light.get_position() - hit.hit_point).normalized();

    //wspĂłĹ‚czynnik rozpraszania
    double diffuse_factor = in_direction.dot(hit.normal);

    //jeĹ›li wspĂłĹ‚czynnik rozpraszania < 0 - zwrĂłÄ‡ czarny
    if (diffuse_factor < 0)
        return MyColor(0,0,0);

    //radiancja jako iloczyn 3 skĹ‚adowych: koloru Ĺ›wiatĹ‚a, koloru materiaĹ‚u i wspĂłĹ‚czynnika rozproszenia
    MyColor final = light.get_color()* color* diffuse_factor;



    return final;

}

Phong::Phong(MyColor n_color, double n_diffuse, double n_specular,double n_specular_e){
     color = n_color;
     diffuse_coeff = n_diffuse;
     specular = n_specular;
     specular_exponent = n_specular_e;
}

Phong::Phong(){
    color = MyColor(0,0,0);
     diffuse_coeff = 0;
     specular = 0;
     specular_exponent = 0;
}

/**definicja metody radiance materiaĹ‚u Phonga*/
MyColor Phong::radiance(PointLight light, HitInfo& hit){

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

MyColor PerfectDiffuse::shade(Raytracer &tracer, HitInfo &hit){

    MyColor total_color;

    QList<PointLight> lights_list = hit.world->get_lights();

    for (int i=0; i<lights_list.size() ;i++){

        Vector3 in_direction = (lights_list[i].get_position() - hit.hit_point).normalized();

        double diffuse_factor = in_direction.dot(hit.normal);

        if (diffuse_factor < 0)
            continue;

        if (hit.world->obstacles(hit.hit_point, lights_list[i].get_position()))
            continue;

        total_color = total_color + lights_list[i].get_color() * color * diffuse_factor;
    }
    return total_color;
}


MyColor Phong::shade( Raytracer &tracer,  HitInfo &hit){

    MyColor total_color;

    QList<PointLight> lights_list = hit.world->get_lights();

    for (int i=0; i<lights_list.size() ;i++){

        Vector3 in_direction = (lights_list[i].get_position() - hit.hit_point).normalized();

        double diffuse_factor = in_direction.dot(hit.normal);

        if (diffuse_factor < 0)
            continue;

        if (hit.world->obstacles(hit.hit_point, lights_list[i].get_position()))
            continue;

        MyColor result = lights_list[i].get_color() * color * diffuse_factor * diffuse_coeff;

        double phong = phong_factor(in_direction, hit.normal, Vector3::contrary(hit.ray.direction));

        if (phong != 0)
            result = result + color * specular * phong;

        total_color = total_color + result;
    }
    return total_color;
}

Reflective::Reflective(MyColor ncolor, double ndiffuse, double nspecular,double nexponent, double nreflectivity){

    direct = Phong (ncolor, ndiffuse, nspecular, nexponent);
    color = ncolor;
    reflectivity = nreflectivity;
}

MyColor Reflective::radiance(PointLight light,HitInfo& hit){
    MyColor radiance = direct.radiance(light, hit);

    return radiance;
}

MyColor Reflective::shade(Raytracer &tracer, HitInfo &hit){

    Vector3 to_camera_direction = Vector3::contrary(hit.ray.direction);

    MyColor radiance = direct.shade(tracer, hit);

    Vector3 reflection_direction = Vector3::reflect(to_camera_direction, hit.normal);

    VRay reflected_ray(hit.hit_point, reflection_direction);

    radiance = radiance + tracer.shaderay(*hit.world, reflected_ray/*, hit.Depth*/) * color * reflectivity;

    return radiance;

}

