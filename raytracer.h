#ifndef RAYTRACER_H
#define RAYTRACER_H
#include<QPixmap>
#include "vector.h"
#include "world.h"
#include "camera.h"
#include "materials.h"

/**
 * @brief The Raytracer class klasa odpowiedzialna za śledzenie promieni
 */
class Raytracer {


    public:
    /**
     * @brief Raytracer konstruktor bezargumentowy ustawiający maksymalną głębię na 1
     */
    Raytracer(){max_depth = 1;}
    /**
     * @brief Raytracer konstruktor
     * @param depth maksymalna głębia obrazu
     */
    inline Raytracer(int depth){max_depth=depth;}

    /**
     * @brief ray_trace metoda śledząca promień i tworząca obraz wynikowy
     * @param world świat
     * @param camera kamera
     * @param image_size wielkość sceny
     * @param distributor sampler
     * @return zwraca obraz w formacie QImage
     *
     */
    QImage ray_trace(World world, Vcamera &camera, QSize image_size, Sampler* distributor);
    /**
     * @brief shaderay metoda sumująca światła, cieniująca (sprawdzająca kolor w danym miejscu)
     * @param world świat
     * @param ray promień
     * @param current_depth obecny poziom głębi
     * @return zwraca konkretny kolor w formacie MyColor
     *
     */
    MyColor shaderay(World world, VRay ray, int current_depth);

private:
    /**
     * @brief max_depth maksymalna głębia, od niej zależy jakość obrazu przy np. obiektach przezroczystych
     */
    int max_depth;



};

#endif // RAYTRACER_H
