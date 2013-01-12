#ifndef CAMERA
#define CAMERA

#include"ray.h"
#include"vector.h"
#include"math/orthonormal_basis.h"
#include"sampler.h"
/**
 * @brief The Vcamera class virtualna klasa kamery
 */
class Vcamera {
public:
    /**
     * @brief GetRayTo virtualna funkcja zwracajaca promien do sledzenia
     * @param relativeLocation pozycja punktu na obrazie do sledzenia
     * @return promien przechodzacy przez zadany punkt
     */
    virtual VRay GetRayTo(Vector2 relativeLocation)=0;
};
/**
 * @brief The Orthogonal class
   klasa kamery ortogonalnej umozliwiajacej render w rzucie ortogonalnym


 */
class Orthogonal : public Vcamera{
public:
    /**
     * @brief Orthogonal
     * @param eye pozycja kamery ortogonalnej
     * @param angle1 kat ktory obejmuje widok kamery
     * @param size wektor poajacy skale kamery
     */
    Orthogonal(Vector3 eye, double angle1, Vector2 size);
    /**
     * @brief GetRayTo funkcja pobierajaca promien do sledzenia
     * @param relativeLocation pozycja punktu na obrazie przez ktory przechodzi obraz
     * @return promien do sledzenia przechodzacy przez pukt podany jako relativeLocation
     */
    virtual VRay GetRayTo(Vector2 relativeLocation);
private:
    /**
     * @brief eye_position pozycja poczatku ukladu wspolzednych kamery
     */
    Vector3 eye_position;
    /**
     * @brief camera_size wielkosc kamery okreslajaca odwrotnosc powiekszenia oraz proporcje obrazu
     */
    Vector2 camera_size;
    /**
     * @brief angle kat ktory obejmuje kamera
     */
    double angle;
};
/**
 * @brief The PinholeCamera class kamera perspektywiczna
 */
class PinholeCamera :public Vcamera{
public:
    /**
     * @brief PinholeCamera konstruktor kamery perspektywicznej
     * @param originl punkt poczatkowy lokalnego ukladu wspolzednych
     * @param look kierunek w ktorym jest skierowana kamera
     * @param upl kierunek wskazujacy gore kamery
     * @param scalel wektor wskazujacy odwrotnosc powiekszenia oraz proporcje obrazu
     * @param distancel odleglosc obrazu od poczatku ukladu wspolzednych
     */
    PinholeCamera(Vector3 originl,Vector3 look,Vector3 upl,Vector2 scalel,double distancel);
    /**
     * @brief GetRayTo funkcja zwracajaca promien do sledzenia dla danej pozycji
     * @param relativeLocation pozycja pixela na obrazie do kolorowania
     * @return promien do sledzenia przechodzacy przez zadany punkt na kliszy
     */
    VRay GetRayTo(Vector2 relativeLocation);

private:
    /**
     * @brief onb baza ortonormalna lokalnego ukladu wspolzednych
     */
    OrthonormalBasis onb;

    /**
     * @brief RayDirection  funkcja zwracajaca kierunek promienia ze wzgledu na przesuniecie na plaszczyznie widoku
     * @param relativeDirection pozycja przez ktora przechodzi promien
     * @return wektor kierunkowy promienia
     */
    Vector3 RayDirection(Vector2 relativeDirection);
    /**
     * @brief origin wektor opisujacy polozenie oka w ktorym zbiegaja sie wszystkie promienie
     */
    Vector3 origin;
    /**
     * @brief lookAt wektor opisujacy kierunek w ktorym jest zwrocona kamera
     */
    Vector3 lookAt;
    /**
     * @brief up wektor wsakzujacy kierunek w ktorym jest gora kamery
     */
    Vector3 up;
    /**
     * @brief distance odleglosc punktu origin od view plane(plaszczyzny w ktorej znajduje sie nasz obraz)
     */
    double distance;
    /**
     * @brief scale wektor odwrotnosci powiekszenia, proporcja obrazu
     */
    Vector2 scale;
};
/****************************************************************************
 *                          Lens Camera                                     *
 ****************************************************************************/

/**
 * @brief The LensCamera class klasa kamery soczewkowej pozwalajacej otrzymac efekt glebi
 */
class LensCamera :public Vcamera{
public:
    /**
     * @brief LensCamera konstruktor kamery soczewkowej
     * @param originl wektor wskazujacy poczatek lokalnego ukladu wspolzednych (pozycje oka)
     * @param lookAtl wektor wskazujacy gdzie skierowana jest kamera
     * @param upl wektor wskazujacy kierunek gory kamery
     * @param scalel wektor odwrotnosci powiekszenia, pozwalajacy zachowac skale obrazka
     * @param distancel wektor odleglosci oka od kliszy
     * @param distributorl Sampler wartosci pseudolosowych pozwalajacy losowac punkty na soczewce
     * @param lensRadiusl srednica soczewki rowniez stala rozmycia
     * @param focall odleglosc oka od focal plane czyli plaszczyzny ostrosci
     */
    LensCamera(Vector3 originl,
    Vector3 lookAtl,
    Vector3 upl,
    Vector2 scalel,
    double distancel,
    Sampler distributorl,
    double lensRadiusl,
               double focall):origin(originl),scale(scalel),distance(distancel),distributor(distributorl),lensRadius(lensRadiusl),focal(focall),onb(originl,lookAtl,upl){}
    /**
     * @brief GetRayTo zwraca promien do sledzenia przechodzacy przez zadany punkt oraz obliczony punkt na plaszczyznie ostrosci
     * @param relativeLocation punkt na kliszy przez ktory ma przechodzic promien
     * @return promien do sledzenia przechodzacy przez zadany punkt na kliszy oraz okreslony punkt na plaszczyznie ostrosci
     */
    VRay GetRayTo(Vector2 relativeLocation);
    /**
     * @brief RayDirection zwraca kierunek dla promienia ktyry zamiezamy zwrocic
     * @param pixelPos pozycja na kliszy przez ktora ma przechodzic promien
     * @param lensPos wylosowana pozycja na soczewce
     * @return kierunek dla promienia ktyry zamiezamy zwrocic do sledzenia
     */
    Vector3 RayDirection(Vector2 pixelPos, Vector2 lensPos);
private:
    /**
     * @brief onb baza ortonormalna lokalnego ukladu wspolzednych
     */
    OrthonormalBasis onb;
    /**
     * @brief origin poczatek lokalnego ukladu wspolzednych, pozycja oka
     */
    Vector3 origin;
    /**
     * @brief scale odwrotnosc powiekszenia, pozwala zachowac proporcje obrazu
     */
    Vector2 scale;
    /**
     * @brief distance odleglosc oka od kliszy
     */
    double distance;
    /**
     * @brief distributor dystrybutor prubek losowych
     */
    Sampler distributor;
    /**
     * @brief lensRadius srednica soczewki moze byc interpretowana jako stala rozmycia
     */
    double lensRadius;
    /**
     * @brief focal odleglosc oka od plaszczyzny ostrosci
     */
    double focal;
};
#endif
