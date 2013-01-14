#ifndef WORLD_H
#define WORLD_H

#include<QList>
#include"geometric_objects.h"
#include"hit_info.h"
#include"ray.h"
#include"point_light.h"


/** @brief World klasa odpowiedzialna za tworzenie świata przedstawianego, który widzi użytkownik*/
class World
{
public:

    /** @brief World konstruktor klasy World tworzący świat o danym kolorze tła*/
    World(MyColor background);
    /** @brief World konstruktor klasy World bezargumentowy*/
    World(): background_color(MyColor(1,1,1)){}
    /** @brief World konstruktor kopiujący klasy World*/
    World(const World &nw): background_color(nw.background_color),objects(nw.objects),lights(nw.lights) {}
    /** @brief add funkcja dodająca do "świata" obiekty geometryczne*/
    void add(GeometricObject *obj);
    /** @brief trace_ray funkcja odpowiedzialna za śledzenie promienia*/
    HitInfo trace_ray(VRay ray);
    /** @brief get_bg_color funkcja zwracająca kolor tła*/
    MyColor get_bg_color();  
    /** @brief add_light funkcja dodająca do "świata" punkty światła*/
    void add_light(PointLight light);
    /** @brief obstacles funkcja szukająca obiektu pomiędzy dwoma punktami - wykorzystywana przy cioniowaniu*/
    bool obstacles(Vector3 a, Vector3 b);
    /** @brief get_lights funkcja zwracająca listę świateł*/
    QList<PointLight> get_lights();



private:

    /** @brief lights lista punktów światła znajdujących się w danym świecie*/
    QList<PointLight> lights;
    /** @brief objects lista obiektów geometrycznych znajdujących się w danym świecie*/
    QList<GeometricObject*> objects;
    /** @brief background_color kolor tła "świata"*/
    MyColor background_color;
};

#endif // WORLD_H
