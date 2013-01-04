#include<QList>
#include"geometric_objects.h"
#include"hit_info.h"
#include"ray.h"

#ifndef WORLD_H
#define WORLD_H

class World
{
public:
    World(QColor background);
    void add(Geometric_object obj);
    hit_info TraceRay(VRay ray);


private:

    QList<Geometric_object> objects;

    QColor background_color;
};

#endif // WORLD_H
