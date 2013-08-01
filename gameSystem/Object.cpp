#include "Object.hpp"

namespace gameSystem {

Object::Object(const Rules& ruleSheet, unsigned randomSeed, Map* parentMap, Vector3i64 pos, Vector3i64 vel, const std::string& type)
    : ruleSheet_(ruleSheet)
    , randomGenerator(randomSeed)
    , parentMap_(parentMap)
    , position_(pos)
    , velocity_(vel)
    , type_(type)
{}

} // namespace gameSystem
