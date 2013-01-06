#ifndef WORLD_H
#define WORLD_H

#include<QList>
#include"geometric_objects.h"
#include"hit_info.h"
#include"ray.h"
#include"point_light.h"


/**klasa odpowiedzialna za tworzenie świata przedstawianego, który widzi użytkownik*/
class World
{
public:

    /**konstruktor klasy World tworzący świat o danym kolorze tła*/
    World(QColor background);
    /**funkcja dodająca do "świata" obiekty geometryczne*/
    void add(GeometricObject *obj);
    /**funkcja odpowiedzialna za śledzenie promienia*/
    HitInfo TraceRay(VRay ray);
    /**funkcja zwracająca kolor tła*/
    QColor get_bg_color();  
    /**funkcja dodająca do "świata" punkty światła*/
    void add_light(PointLight light);


private:

    /**lista punktów światła znajdujących się w danym świecie*/
    QList<PointLight> lights;
    /**lista obiektów geometrycznych znajdujących się w danym świecie*/
    QList<GeometricObject*> objects;
    /**kolor tła "świata"*/
    QColor background_color;
};

#endif // WORLD_H
