#include "geometric_objects.h"

QColor Geometric_object::getColor(){
    return color;
}

void Geometric_object::setColor(QColor newColor){
    color = newColor;
}

Sphere::Sphere(Vector3 newCenter, double newRadius, QColor newColor){
    center = newCenter;
    radius = newRadius;
    color = newColor;
}

