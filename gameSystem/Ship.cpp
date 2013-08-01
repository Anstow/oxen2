#include "Ship.hpp"

#include <random>

namespace gameSystem {

Ship::Ship(const Rules& ruleSheet, unsigned randomSeed, Map* map, Vector3i64 pos, Vector3i64 vel)
    : Object(ruleSheet, randomSeed, map, pos, vel, "ship")
{}

void Ship::updateObject(float timeInterval) {
    // TODO: update ship
}

void Ship::hitByObject(const Object& obj) {
    // TODO: hit by missiles
}

void Ship::hitByWeapon(const WeaponDamage& weapon) {
    int internalDamage = 0;
    switch (weapon.type)
    {
        case WeaponType::laser:
            // TODO: shields 
        case WeaponType::railgun:
            std::uniform_int_distribution<> uniformDist(0, armour_.getSize() - 1);
            internalDamage = armour_.damageArmour(weapon.damageTemplate,
                    { uniformDist(getRandom()), uniformDist(getRandom()) });
            break;
    }
    // TODO: internal damage
}

void Ship::internalDamage(unsigned damage) {
    unsigned structuralDamage(0);
    while (damage > 0) {
        unsigned secondaryDamage(0);

        std::poisson_distribution<> poisonDist(getRules().structuralDamageProbability * damage);
        structuralDamage += poisonDist(getRandom());

        poisonDist = std::poisson_distribution<>(getRules().componentDamageProbability * damage);

        int numberOfInternalHits = poisonDist(getRandom());
        for (int i = 0; i < numberOfInternalHits; i++) {
            std::uniform_int_distribution<> uniformDist(0, sizeOfComponents - 1);
            int struckComponent = uniformDist(getRandom());
            auto itr = components_.begin();
            struckComponent -= itr->second.getSize();
            while(struckComponent > 0) {
                ++itr;
                struckComponent -= itr->second.getSize();
            }
            secondaryDamage += itr->second.damageComponent(damage);
        }

        damage = secondaryDamage;
    }

    // TODO: killing crew, damaging automata etc...
    
    // If the ship has sustained enough damage it should disintergrate
    if (structuralDamage > structure_) {
        disintergrate(structuralDamage - structure_);
        structure_ = 0;
    } else {
        structure_ -= structuralDamage;
        if (structure_ < minCrewableStructure_) {
            // if it is no longer safe to crew evacuate the crew
            evacuateCrew();
        }
    }
}

void Ship::disintergrate(unsigned excessDamage) {
    // TODO: disintergrating ships
} 

void Ship::evacuateCrew() {
    // TODO: evacuating ships
}

} // namespace gameSystem
