#ifndef GAMESYSTEM_ARMOUR_HPP
#define GAMESYSTEM_ARMOUR_HPP

#include "../engine/utility/Vector2.hpp"

#include "Object.hpp"
#include "DamageTemplate.hpp"

namespace gameSystem {

class Armour
{
    unsigned* armour_;

    unsigned size_;
    unsigned strength_;
    float unitWeight_;
    
    unsigned long currentArmour_;
    
    unsigned getArmour(const oxEngine::Vector2i& point) const;
    void setArmour(const oxEngine::Vector2i& point, unsigned strength);
    unsigned damageArmourPoint(oxEngine::Vector2i point, unsigned damage);

public:
    Armour();
    Armour(unsigned size, unsigned strength, float unitWeight);
    ~Armour();

    void repairArmour();
    unsigned damageArmour(const DamageTemplate& damage, const oxEngine::Vector2i& point);

    unsigned getSize() const;
    unsigned long getCurrentArmour() const;
    float getDamagePercentage() const;
    float getCurrentWeight() const;
};

inline unsigned Armour::getArmour(const oxEngine::Vector2i& point) const {
    return armour_[(point.y + size_ % size_)*size_ + (point.x + size_ % size_)];
}

inline void Armour::setArmour(const oxEngine::Vector2i& point, unsigned strength) {
    armour_[(point.y + size_ % size_)*size_ + (point.x + size_ % size_)] = strength;
}

inline unsigned Armour::getSize() const {
    return size_;
}

inline unsigned long Armour::getCurrentArmour() const {
    return currentArmour_;
}

inline float Armour::getDamagePercentage() const {
    return 1.0f - currentArmour_ / (size_*size_*strength_);
}

inline float Armour::getCurrentWeight() const {
    return currentArmour_ * unitWeight_;
}

} // using gameSystem

#endif // GAMESYSTEM_ARMOUR_HPP
