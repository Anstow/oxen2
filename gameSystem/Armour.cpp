#include "Armour.hpp"

namespace gameSystem {

Armour::Armour() {}

Armour::Armour(unsigned size, unsigned strength, float unitWeight) 
    : armour_(new unsigned[size * size])
    , size_(size)
    , strength_(strength)
    , unitWeight_(unitWeight)
{
    repairArmour();
}

Armour::~Armour() {
    delete[] armour_;
}

void Armour::repairArmour() {
    currentArmour_ = size_*size_*strength_;
    for (unsigned i = 0; i < size_; i++) {
        armour_[i] = strength_;
    }
}

unsigned Armour::damageArmour(const DamageTemplate& damage, const oxEngine::Vector2i& point) {
    unsigned internalDamage = 0;
    for(int i = -damage.radius_; i <= damage.radius_; ++i) {
        for (int j = -damage.radius_; j <= damage.radius_; ++j) {
            internalDamage += damageArmourPoint(point + oxEngine::Vector2i{i, j}, damage.getPower({i, j}));
        }
    }
    return internalDamage;
}

unsigned Armour::damageArmourPoint(oxEngine::Vector2i point, unsigned damage) {
    point.x = point.x + size_ % size_;
    point.y = point.y + size_ % size_;
    if (armour_[point.y*size_ + point.x] >= damage) {
        armour_[point.y*size_ + point.x] -= damage;
        currentArmour_ -= damage;
        return 0;
    } else {
        currentArmour_ -= armour_[point.y*size_ + point.x];
        armour_[point.y*size_ + point.x] = 0;
        return damage - armour_[point.y*size_ + point.x];
    }
}

} // namespace gameSystem
