#include "materials.h"
#include<QColor>
#include "hit_info.h"
#include <math.h>
#include "raytracer.h"
#include<iostream>
#include "ray.h"



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
/*MyColor PerfectDiffuse::radiance(PointLight light, HitInfo &hit){

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

}*/

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
/*MyColor Phong::radiance(PointLight light, HitInfo& hit){

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

}*/

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


MyColor Phong::shade(Raytracer &tracer,  HitInfo &hit){

    MyColor total_color(0,0,0);

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

/*MyColor Reflective::radiance(PointLight light,HitInfo& hit){
    MyColor radiance = direct.radiance(light, hit);

    return radiance;
}*/

MyColor Reflective::shade(Raytracer &tracer, HitInfo &hit){

    Vector3 to_camera_direction = Vector3::contrary(hit.ray.direction);

    MyColor radiance = direct.shade(tracer, hit);

    Vector3 reflection_direction = Vector3::reflect(to_camera_direction, hit.normal);

    VRay reflected_ray(hit.hit_point, reflection_direction);

    radiance = radiance + tracer.shaderay(*hit.world, reflected_ray, hit.depth) * color * reflectivity;

    return radiance;

}



Transparent::Transparent(MyColor ncolor, double ndiffuse, double nspecular,double nexponent, double nreflection, double nrefraction, double ntransmission){
        color = ncolor;
        direct = Phong(color, ndiffuse, nspecular, nexponent);
        transmission = ntransmission;
        reflection = nreflection;
        specular = nspecular;
        refraction = nrefraction;
}



MyColor Transparent::shade(Raytracer &tracer, HitInfo &hit){


    MyColor final = direct.shade(tracer, hit);

    Vector3 to_camera_direction = Vector3::contrary(hit.ray.direction);

    double cos_incident_angle = hit.normal.dot(to_camera_direction);

    double eta = cos_incident_angle > 0 ? refraction : 1 / refraction;

    double refraction_coeff = find_refraction_coeff(eta, cos_incident_angle);
    Vector3 v=Vector3::reflect(to_camera_direction, hit.normal);
    VRay reflected_ray(hit.hit_point, v);

    MyColor reflection_color = color * reflection;

    if (is_total_internal_reflection(refraction_coeff))
        final = final + tracer.shaderay(*hit.world, reflected_ray, hit.depth);
    else
    {
        VRay transmitted_ray = compute_transmission_direction(hit.hit_point, to_camera_direction, hit.normal, eta, sqrt(refraction_coeff), cos_incident_angle);
        MyColor transmission_color = compute_transmission_color(eta);
        final = final + reflection_color * tracer.shaderay(*hit.world, reflected_ray, hit.depth);
        final = final + transmission_color * tracer.shaderay(*hit.world, transmitted_ray, hit.depth);
    }

    return final;


}

MyColor Transparent::compute_transmission_color(double eta){
    return ((MyColor(1,1,1) * transmission) / (eta * eta));
}

double Transparent::find_refraction_coeff(double eta, double cos_incident_angle){
    return (1-(1-cos_incident_angle*cos_incident_angle)/(eta*eta));
}

bool Transparent::is_total_internal_reflection(double refraction_coeff){
    return refraction_coeff < 0;
}

VRay Transparent::compute_transmission_direction(Vector3 hit_point, Vector3 to_camera_direction, Vector3 normal, double eta, double cos_transmitted_angle, double cos_incident_angle){
    if (cos_incident_angle < 0){
        normal = Vector3::contrary(normal);
        cos_incident_angle = -cos_incident_angle;
    }

    Vector3 direction = (Vector3::contrary(to_camera_direction) / eta)- (normal *(cos_transmitted_angle - cos_incident_angle / eta));

    return VRay(hit_point, direction);
}

