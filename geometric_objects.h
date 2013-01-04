#include "ray.h"
#include <QColor>


class Geometric_object {

    public:

    virtual bool HitTest(VRay ray, double &distance);
    QColor getColor();
    void setColor(QColor newColor){color = newColor;};




    private:

    QColor color;

};

class Sphere: GeometricObject {

    public:

    Sphere(Vector3 newCenter, double newRadius, QColor newColor)
    {
        center = newCenter;
        radius = newRadius;
        color = this->setColor(newColor);
    }

    bool HitTest(VRay ray, double &distance)
    {
        //@to do
    }

};
