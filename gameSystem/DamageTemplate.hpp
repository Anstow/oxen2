#ifndef GAMESYSTEM_DAMAGETEMPLATE_HPP
#define GAMESYSTEM_DAMAGETEMPLATE_HPP

#include "../engine/utility/Vector2.hpp"
#include <cmath>

namespace gameSystem {

enum DamageType {
    beam,
    deep_crater,
    shallow_crater
};

struct DamageTemplate
{
    DamageType type_;
    int radius_;
    unsigned power_;

    unsigned getPower(const oxEngine::Vector2i& point) const;
};

} // using gameSystem

#endif // GAMESYSTEM_DAMAGETEMPLATE_HPP
