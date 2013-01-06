#include "orthonormal_basis.h"


OrthonormalBasis::OrthonormalBasis(Vector3 eye,Vector3 lookAt, Vector3 up){
    w=eye - lookAt;
    w=w.normalized();
    u=up.cross(w);
    u=u.normalized();
    v=w.cross(u);
}
/**
operator mnożenia bazy przez wektor
*/
Vector3 OrthonormalBasis::operator*(Vector3 v){
    return ((this->u*v.getX())+(this->v*v.getY())+(this->w*v.getZ()));
}
