
#include"camera.h"
#include<math.h>
#include"ray.h"


VRay Orthogonal::GetRayTo(Vector2 pictureLocation) {
    //kierunek w kt�rym jest skierowane s� promienie wychodz�ce
    // z kamery
    Vector3 direction(sin(angle), 0, cos(angle));
    //normalizujemy kierunek
    direction = direction.normalized();
    //oddalenie pocz�tku kamery od jej po�o�enia
    Vector2 offset_center(pictureLocation.x * camera_size.x,
            pictureLocation.y * camera_size.y);

    //obliczanie finalnego po�o�enia pocz�tku promienia
    Vector3 position(eye_position.getX() + offset_center.x * cos(angle),
            eye_position.getY() + offset_center.y,
            eye_position.getZ() + offset_center.x * sin(angle));

    return VRay(position, direction);
}

Orthogonal::Orthogonal(Vector3 eye, double angle1, Vector2 size) {
    eye_position = eye;
    camera_size = size;
    angle = angle1;
}
/************************************************************************************************
 *									Pinhole Camera												*
 ************************************************************************************************/

///domyślny konstruktor klasy
PinholeCamera::PinholeCamera(Vector3 originl, Vector3 look, Vector3 upl, Vector2 scalel, double distancel):onb(originl,look,upl){
    this->origin=originl;
    this->lookAt=look;
    this->up=upl;
    this->distance=distancel;
    this->scale=scalel;
}


VRay PinholeCamera::GetRayTo(Vector2 relativeLocation){
    Vector2 vs=Vector2(relativeLocation.x*scale.x,relativeLocation.y*scale.y);
    Vector3 v=this->RayDirection(vs);
    return VRay(origin,v);
}


    /// funkcja zwracająca kierunek promienia ze względu na przesunięcie na płaszczyźnie widoku
Vector3 PinholeCamera::RayDirection(Vector2 relativeDirection){
    return onb*Vector3(relativeDirection.x,relativeDirection.y,-distance);

}
/************************************************************************************************
 *									Lens Camera             									*
 ************************************************************************************************/

VRay LensCamera::GetRayTo(Vector2 relativeLocation){
    Vector2 pixelPosition =Vector2(relativeLocation.x*scale.x,relativeLocation.y*scale.y);
    Vector2 l=distributor.Single();
    Vector2 lensPoint= Vector2(l.x*lensRadius,l.y*lensRadius);
    Vector3 rayOrigin= origin+(onb*Vector3(lensPoint.x,lensPoint.y,0));
    Vector3 rayDir=RayDirection(pixelPosition,lensPoint);
    return VRay(rayOrigin,rayDir);
}

Vector3 LensCamera::RayDirection(Vector2 pixelPos,Vector2 lensPos){
    Vector2 p=pixelPos*focal/distance;
    return onb*Vector3(p.x-lensPos.x,p.y-lensPos.y,-focal);
}
