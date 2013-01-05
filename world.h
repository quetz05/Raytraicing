#include<QList>
#include"geometric_objects.h"
#include"hit_info.h"
#include"ray.h"

#ifndef WORLD_H
#define WORLD_H

/**klasa odpowiedzialna za tworzenie świata przedstawianego, który widzi użytkownik*/
class World
{
public:

    /**konstruktor klasy World tworzący świat o danym kolorze tła*/
    World(QColor background);
    /**funkcja dodająca do "świata" obiekty geometryczne*/
    void add(GeometricObject obj);
    /**funkcja odpowiedzialna za śledzenie promienia*/
    HitInfo TraceRay(VRay ray);


private:

    /**lista obiektów geometrycznych znajdujących się w danym świecie*/
    QList<GeometricObject> objects;
    /**kolor tła "świata"*/
    QColor background_color;
};

#endif // WORLD_H
