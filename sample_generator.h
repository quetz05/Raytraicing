#ifndef SAMPLE_GENERATOR_H
#define SAMPLE_GENERATOR_H
#include"vector.h"
#include<stdlib.h>
/**
 * @brief The VSampleGenerator class wirtualna klasa generatora probek
 */
class VSampleGenerator{
public:
    /**
     * @brief VSampleGenerator domyslny konstruktor
     */
    VSampleGenerator(){}
    /**
     * @brief sample gneneruje zestaw probek
     * @param tab tablica na probki
     * @param cout ilosc probek do wygenerowania
     */
    virtual void sample(Vector2 *tab,int cout)=0;
};

/****************************************************************************
 *                          Pure random generator                           *
 ****************************************************************************/
/**
 * @brief The RandomGenerator class klasa losowego generatora probek
 */
class RandomGenerator : public VSampleGenerator{
public:
    /**
     * @brief RandomGenerator konstruktor inicjalizujacy generator
     * @param seedl ziarno inicjalizujace losowosc generatora
     */
    RandomGenerator(int seedl): seed(seedl){}
    /**
    * @brief sample funkcja generujaca zestaw probek
    * @param tab tablica na probki
    * @param cout liczba probek do wygenerowania
    */
   virtual void sample(Vector2 *tab,int cout);
private:
    /**
     * @brief seed ziarno inicjalizujace generator
     */
    int seed;
};
/****************************************************************************
 *                          Regular generator                               *
 ****************************************************************************/
/**
 * @brief The RegularGenerator class klasa regularnego generatora probek
 */
class RegularGenerator : public VSampleGenerator{
public:
    /**
     * @brief sample funkcja generujaca zestaw probek
     * @param tab tablica na probki
     * @param cout liczba probek do wygenerowania zalecane 2^n
     */
    virtual void sample(Vector2 *tab,int cout);
};
/****************************************************************************
 *                          Jittered generator                              *
 ****************************************************************************/
/**
 * @brief The JitteredGenerator class clasa generujaca probki metoda jittered
 */
class JitteredGenerator : public VSampleGenerator{
public:
    /**
     * @brief JitteredGenerator domyslny konstruktor klasy
     * @param seedl ziarno inicjujace losowosc
     */
    JitteredGenerator(int seedl): seed(seedl){}
    /**
     * @brief sample funkcja generujaca zestaw probek
     * @param tab tablica na probki
     * @param cout liczba probek do wygenerowania zalecana 2^n
     */
    virtual void sample(Vector2 *tab,int cout);
private:
    /**
     * @brief seed ziarno inicjalizujace losowosc
     */
    int seed;
};
#endif // SAMPLE_GENERATOR_H
