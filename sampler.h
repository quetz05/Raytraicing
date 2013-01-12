#ifndef SAMPLER_H
#define SAMPLER_H
#include<QList>
#include"sample_generator.h"
#include"sample_distrybutor.h"
/**
 * @brief The Sampler class klasa przechowujaca wygenerowane zestawy probek i zwracajaca kolejne probki z losowego zestawu
 */
class Sampler{
public:
    /**
     * @brief Sampler konstruktor pusty potrzebny tam gdzie mamy pole konstruktora i nie chcemy go uzywac
     */
    Sampler(){}
    /**
     * @brief Sampler konstruktor tworzacy kontener z probkami
     * @param sampler referencja na generator probek
     * @param mapper referencja na dystrybutor probek
     * @param sampleCt liczba probek do wygenerowania w zestawie
     * @param setCt liczba zestawow do wygenerowania
     * @param seed ziarno inicjalizujace losowosc
     */
    Sampler(VSampleGenerator& sampler, VSampleDistributor& mapper,
            int sampleCt, int setCt,int seed);
    /**
     *  destruktor usuwajacy dynamicznie tworzone tablice sampli
     */
    ~Sampler();
    /**
     * @brief Single funkcja zwracajaca probke
     * @return kolejna probka z zestawu jezeli jeszcze jakies sa jezeli nie losuje nowy zestaw
     */
    Vector2 Single();
    /**
     * @brief getSampleCout funkcja zwracajaca ilosc probek w zestawie
     * @return
     */
    int getSampleCout(){return sampleCout;}
private:
    /**
     * @brief seed ziarno inicjalizujace losowosc
     */
    int seed;
    /**
     * @brief sets lista zestawow probek
     */
    QList<Vector2*> sets;
    /**
     * @brief sampleNdx index mowiacy ktora probka byla pobierana ostatnia
     */
    int sampleNdx;
    /**
     * @brief setNdx index mowiacy z ktorego zestawu pobieramy probki
     */
    int setNdx;
    /**
     * @brief sampleCout liczba mowiaca ile jest probek w zestawie
     */
    int sampleCout;
    /**
     * @brief setCout zmienna mowiaca ile jest zestawow
     */
    int setCout;

};

#endif // SAMPLER_H
