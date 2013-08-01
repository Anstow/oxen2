#ifndef GAMESYSTEM_SHIP_HPP
#define GAMESYSTEM_SHIP_HPP

#include "Object.hpp"
#include "WeaponDamage.hpp"
#include "Armour.hpp"
#include "Component.hpp"
#include "Map.hpp"

#include "../engine/utility/Vector3.hpp"

#include <vector>
#include <map>

namespace gameSystem {

class Ship : public Object
{
    unsigned shipId_;

    std::string shipType_;

    Armour armour_;

    unsigned crew_;
    unsigned automata_;
    unsigned structure_;
    unsigned minCrewableStructure_;
    unsigned oxygen_;
    unsigned minOxygenSuply_;

    std::multimap<ComponentType, Component> components_;
    unsigned sizeOfComponents;

public:
    Ship(const Rules& ruleSheet, unsigned randomSeed, Map* map, Vector3i64 pos, Vector3i64 vel);

    virtual void updateObject(float timeInterval) override final;

    virtual void hitByObject(const Object& obj) override final;
    virtual void hitByWeapon(const WeaponDamage& weaponDamage) override final;

    void internalDamage(unsigned damage);

    void disintergrate(unsigned excessDamage);
    void evacuateCrew();

    bool operator<(const Ship& rhs);
};

inline bool Ship::operator<(const Ship& rhs) {
    return shipId_ < rhs.shipId_;
}

} // namespace gameSystem

#endif // GAMESYSTEM_SHIP_HPP
