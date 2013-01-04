#include "ray.h"
#include "vector.h"
#include <QColor>


class Geometric_object {

    public:

    virtual bool HitTest(VRay ray, double &distance);
    QColor getColor();
    void setColor(QColor newColor);




    protected:

    QColor color;

};

class Sphere: Geometric_object {

    public:

    Sphere(Vector3 newCenter, double newRadius, QColor newColor);


    bool HitTest(VRay ray, double &distance);

    private:

    Vector3 center;
    double radius;

};
