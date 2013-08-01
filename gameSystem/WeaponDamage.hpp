#ifndef GAMESYSTEM_WEAPONDAMAGE_HPP
#define GAMESYSTEM_WEAPONDAMAGE_HPP

#include "DamageTemplate.hpp"

#include "../engine/utility/Vector3.hpp"

namespace gameSystem {

enum WeaponType {
    laser,
    railgun
};

struct WeaponDamage
{
    WeaponType type;
    DamageTemplate damageTemplate;
};

} // namespace gameSystem

#endif // GAMESYSTEM_WEAPONDAMAGE_HPP

