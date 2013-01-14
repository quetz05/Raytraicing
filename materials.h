/**nagłówek zawierający deklarację klas i funkcji związanych z materiałem*/
#ifndef MATERIAL_H
#define MATERIAL_H
#include <QColor>
#include "point_light.h"
#include "mycolor.h"

class HitInfo;
class Raytracer;
class VRay;

/**
 * @brief Material klasa abstrakcyjna opisująca materiał
 */
class Material{
    public:

        /**
         * @brief shade metoda sprawdzająca cieniowanie materiału
         * @param tracer dzięki niemu możemy śledzić promień
         * @param hit informacje o trafieniu promienia
         * @return zwraca kolor w danym miejscu materiału
         */
        virtual MyColor shade(Raytracer &tracer, HitInfo &hit)=0;

    protected:

        /**
         * @brief color kolor materiału
         */
        MyColor color;

};

/**
 * @brief PerfectDiffuse klasa opisująca materiał idealnie rozpraszający
 */
class PerfectDiffuse: public Material{

    public:

        /**
         * @brief PerfectDiffuse konstruktor
         * @param c kolor materiału
         */
        PerfectDiffuse(MyColor c){color=c;}
        /**
         * @brief shade metoda sprawdzająca cieniowanie materiału idealnie rozpraszającego
         * @param tracer dzięki niemu możemy śledzić promień
         * @param hit informacje o trafieniu promienia
         * @return zwraca kolor w danym miejscu materiału idealnie rozpraszającego
         */
        MyColor shade(Raytracer &tracer, HitInfo &hit);
};

/**
 * @brief Phong klasa opisująca materiał Phonga
 */
class Phong : public Material{

    public:

        /**
         * @brief Phong konstruktor bezargumentowy
         */
        Phong();
        /**
         * @brief PerfectDiffuse konstruktor
         * @param n_color kolor materiału
         * @param n_diffuse współczynnik rozproszenia światła (jaka część światła jest rozpraszana)
         * @param n_specular rozbłysk (jak silne są rozbłyski)
         * @param n_specular_e wykładnik rozbłysku (jaki wykładnik jest użyty do modelowania rozbłysków)
         */
        Phong(MyColor n_color, double n_diffuse, double n_specular,double n_specular_e);
        /**
         * @brief phong_factor metoda obliczająca współczynnik Phonga
         * @param in_direction punkt kierunkowy
         * @param normal normalna
         * @param to_camera_direction punkt kierunku kamery
         * @return współczynnik Phong
         */
        double phong_factor(Vector3 in_direction, Vector3 normal, Vector3 to_camera_direction);
        /**
         * @brief shade metoda sprawdzająca cieniowanie materiału Phonga
         * @param tracer dzięki niemu możemy śledzić promień
         * @param hit informacje o trafieniu promienia
         * @return zwraca kolor w danym miejscu materiału Phonga
         */
        MyColor shade(Raytracer &tracer, HitInfo &hit);

    private:

            /**
             * @brief diffuse_coeff zmienna określająca wspólczynnik rozproszenia
             */
             double diffuse_coeff;
             /**
              * @brief specular zmienna określająca rozbłysk
              */
             double specular;
             /**
              * @brief specular_exponent zmienna określająca wyznacznik rozbłysku
              */
             double specular_exponent;
};


/**
 * @brief Reflective klasa opisująca materiał modelujący odbicie
 */
class Reflective : public Material{

    public:

        /**
         * @brief Reflective konstruktor klasy
         * @param ncolor kolor materiału
         * @param ndiffuse współczynnik rozproszenia światła (jaka część światła jest rozpraszana)
         * @param nspecular rozbłysk (jak silne są rozbłyski)
         * @param nexponent wykładnik rozbłysku (jaki wykładnik jest użyty do modelowania rozbłysków)
         * @param nreflectivity odbicie światła (jak mocno materiał odbija światło)
         */
        Reflective(MyColor ncolor, double ndiffuse, double nspecular,double nexponent, double nreflectivity);
        /**
         * @brief shade metoda sprawdzająca cieniowanie materiału modelującego odbicie
         * @param tracer dzięki niemu możemy śledzić promień
         * @param hit informacje o trafieniu promienia
         * @return zwraca kolor w danym miejscu materiału modelującego odbicie
         */
        MyColor shade(Raytracer &tracer, HitInfo &hit);

    private:
            /**
             * @brief reflectivity odbicie światła - jak mocno materiał odbija światło
             */
             double reflectivity;
             /**
              * @brief direct obiekt klasy Phong, który zawiera atrybuty materiału modelującego odbicie
              */
             Phong direct;
};

/**
 * @brief Transparent klasa opisująca materiał przezroczysty
 */
class Transparent : public Material
{

    public:

        /**
         * @brief Transparent kontruktor klasy
         * @param ncolor kolor materiału
         * @param ndiffuse współczynnik rozproszenia światła (jaka część światła jest rozpraszana)
         * @param nspecular rozbłysk (jak silne są rozbłyski)
         * @param nexponent wykładnik rozbłysku (jaki wykładnik jest użyty do modelowania rozbłysków)
         * @param nreflection odbicie
         * @param nrefraction refrakcja
         * @param ntransmission transmisja
         */
        Transparent(MyColor ncolor, double ndiffuse, double nspecular,double nexponent, double nreflection, double nrefraction, double ntransmission);
        /**
         * @brief shade metoda sprawdzająca cieniowanie materiału przezroczystego
         * @param tracer dzięki niemu możemy śledzić promień
         * @param hit informacje o trafieniu promienia
         * @return zwraca kolor w danym miejscu materiału przezroczystego
         */
        MyColor shade(Raytracer &tracer, HitInfo &hit);        
        /**
         * @brief compute_transmission_color funkcja wyliczająca kolor transmisji
         * @param eta współczynnik załamania ośrodka
         * @return zwraca kolor transmisji
         */
        MyColor compute_transmission_color(double eta);
        /**
         * @brief find_refraction_coeff funkcja wyliczająca współczynnik refrakcji
         * @param eta współczynnik załamania ośrodka
         * @param cos_incident_angle cosinus kąta załamania
         * @return zwraca współczynnik refrakcji
         */
        double find_refraction_coeff(double eta, double cos_incident_angle);
        /**
         * @brief is_total_internal_reflection funkcja sprawdzająca czy mamy do czynienia z całkowitym wewnętrznym odbiciem
         * @param refraction_coeff współczynnik refrakcji (załamania)
         * @return zwraca true/false zależnie od wyniku
         */
        bool is_total_internal_reflection(double refraction_coeff);
        /**
         * @brief compute_transmission_color funkcja wyliczająca kierunek transmisji (dalszego odbicia)
         * @param hit_point miejsce trafienia promienia
         * @param to_camera_direction punkt kierunku do kamery
         * @param normal normalna
         * @param eta współczynnik załamania ośrodka
         * @param cos_transmitted_angle cosinus kąta transmisji promienia
         * @param cos_incident_angle cosinus kąta załamania
         * @return zwraca kierunek transmisji (punkt)
         */
        VRay compute_transmission_direction(Vector3 hit_point, Vector3 to_camera_direction, Vector3 normal, double eta, double cos_transmitted_angle, double cos_incident_angle);

    private:

        /**
         * @brief direct obiekt klasy Phong, który zawiera atrybuty materiału przezroczystego
         */
        Phong direct;
        /**
         * @brief refraction zmienna określająca refrakcję
         */
        double refraction;
        /**
         * @brief reflection zmienna określająca odbicie
         */
        double reflection;
        /**
         * @brief transmission zmienna określająca transmisję promienia
         */
        double transmission;
        /**
         * @brief specular zmienna określająca rozbłysk
         */
        double specular;
};



#endif // MATERIAL_H

