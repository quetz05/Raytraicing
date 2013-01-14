#ifndef RAY
#define RAY

#include <limits>
#include "vector.h"


#define EPSILON 0.00001
#define HUGER std::numeric_limits<double>::max();
/**
 * @brief The VRay class klasa implementująca promień
 */
class VRay{
public:
    /**
     * @brief VRay konstruktor klasy
     * @param origin początek promienia
     * @param direction kierunek promienia
     */
    inline VRay(Vector3 &origin, Vector3 &direction){
        this->origin = origin;
        this->direction = direction.normalized();
    }

    /**
     * @brief VRay konstruktor bezargumentowy
     */
    inline VRay(){
        origin = Vector3();
        direction = Vector3();
    }

    /**
     * @brief origin początek promienia
     */
    Vector3 origin;
    /**
     * @brief direction kierunek promienia
     */
    Vector3 direction;
};
#endif
