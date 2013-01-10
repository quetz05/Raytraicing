#ifndef CAMERA
#define CAMERA

#include"ray.h"
#include"vector.h"
#include"math/orthonormal_basis.h"
#include"sampler.h"
/** ogolny interface kamery */
class Vcamera {
public:
	/** prototyp funkcji pobierajacej promien z kamery do sledzenia */
	virtual VRay GetRayTo(Vector2 relativeLocation)=0;
};
/**
	klasa kamery ortogonalnej umozliwiajacej render w rzucie ortogonalnym
*/

class Orthogonal : public Vcamera{
public:
    Orthogonal(Vector3 eye, double angle1, Vector2 size);
    virtual VRay GetRayTo(Vector2 relativeLocation);
private:
    Vector3 eye_position;
    Vector2 camera_size;
    double angle;
};
/**
	kamera perspektywiczna dzialajaca na zasadzie kamery otworkowej 
*/
class PinholeCamera :public Vcamera{
public:
	///domyslny konstruktor klasy 
    PinholeCamera(Vector3 originl,Vector3 look,Vector3 upl,Vector2 scalel,double distancel);
	///zwraca promien do sledzenia dla klasy slezdzacej 
	VRay GetRayTo(Vector2 relativeLocation);
	
private:
    OrthonormalBasis onb;
	/// funkcja zwracajaca kierunek promienia ze wzgledu na przesuniecie na plaszczyznie widoku
	Vector3 RayDirection(Vector2 relativeDirection);
	/// wektor opisujacy punkt polozenia oka w ktorym zbiegaja sie wszystkie promienie
	Vector3 origin;
	/// wektor opisujacy kierunek patrzenia
	Vector3 lookAt;
	/// wektor opisujacy orientacje wzgledem kierunku patrzenia czyli wskazujacy gore 
	Vector3 up;
	/// odleglosc punktu origin od view plane(plaszczyzny w ktorej znajduje sie nasz obraz)
	double distance;
    /// skala obrazka pomaga utrzymac wszystko w proporcjach gdy zmieniamy proporcje obrazu
    Vector2 scale;
};
/****************************************************************************
 *                          Lens Camera                                     *
 ****************************************************************************/
class LensCamera :public Vcamera{
public:
    LensCamera(Vector3 originl,
    Vector3 lookAtl,
    Vector3 upl,
    Vector2 scalel,
    double distancel,
    Sampler distributorl,
    double lensRadiusl,
               double focall):origin(originl),scale(scalel),distance(distancel),distributor(distributorl),lensRadius(lensRadiusl),focal(focall),onb(originl,lookAtl,upl){
    }
    VRay GetRayTo(Vector2 relativeLocation);
    Vector3 RayDirection(Vector2 pixelPos, Vector2 lensPos);
private:
    OrthonormalBasis onb;
    Vector3 origin;
    Vector2 scale;
    double distance;
    Sampler distributor;
    double lensRadius;
    double focal;


};
#endif

