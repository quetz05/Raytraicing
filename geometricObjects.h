#include "ray.h"

class GeometricObject
{
    public:
    //@do dodania funkcja koloru z QT
    virtual bool HitTest(Ray ray, double &distance);

};
