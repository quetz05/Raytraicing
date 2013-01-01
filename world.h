#include<QVector>
#include"geometricObjects.h"
#include"hit_info.h"
#include"ray.h"

#ifndef WORLD_H
#define WORLD_H

class World
{
public:
    World(QColor background);
    void add(GeometricObject obj);
    hit_info TraceRay(Ray ray);


private:
    QVector<GeometricObject> objects;
    QColor background_color;
};

#endif // WORLD_H
