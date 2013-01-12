#ifndef SAMPLE_DISTRYBUTOR_H
#define SAMPLE_DISTRYBUTOR_H
#include"vector.h"
/**
 * @brief The VSampleDistributor class klasa wirtualna dystrybutora probek
 */
class VSampleDistributor
{
public:
    /**
     * @brief VSampleDistributor konstruktor
     */
    VSampleDistributor(){}
    /**
     * @brief MapSample funkcja mapujaca probke na dowolny obszar
     * @param sample probka do zmapowania
     * @return zmapowana probka
     */
    virtual Vector2 MapSample(Vector2 sample)=0;

};
/**
 * @brief The SquareDistributor class klasa dystrybutora prubek na kwadrat jednostokowy
 */
class SquareDistributor : public VSampleDistributor{
    /**
     * @brief MapSample mapuje probke na jednostkowy kwadrat
     * @param v probka do zmapowania
     * @return zmapowana probka
     */
    virtual Vector2 MapSample(Vector2 v);
};
/**
 * @brief The DiskDistributor class klasa dystrybutora probek na kolo o promieniu 1
 */
class DiskDistributor : public VSampleDistributor{
    /**
     * @brief MapSample mapuje probke na kolo o promieniu 1
     * @param sample probka do zmapowania
     * @return zmapowana probka
     */
    virtual Vector2 MapSample(Vector2 sample);
};
#endif // SAMPLE_DISTRYBUTOR_H
