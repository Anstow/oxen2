#include "Map.hpp"
#include "Object.hpp"

#include <algorithm>
#include <stdexcept>

namespace gameSystem {

Map::Map(const Rules& ruleSheet, int systemNumber)
    : ruleSheet_(ruleSheet)
    , systemNumber_(systemNumber)
{}

void Map::updateSystem(float timeInterval) {
    for (auto& obj : objects_) {
        obj->updateObject(timeInterval);
    }
}

void Map::insertSystemObject(std::unique_ptr<Object>&& obj) {
    if (not obj.get()) {
        throw std::invalid_argument("You cannot add a null entity");
    }
    
    obj->parentMap_ = this;
    objects_.push_back(std::move(obj));
}

std::unique_ptr<Object> Map::releaseObject(Object* obj) {
    // Find the relavent entity
    auto itr = std::find_if(objects_.begin(), objects_.end(),
            [&obj](std::unique_ptr<Object>& object)
            {
                return obj == object.get();
            });

    if (itr == objects_.end()) {
        // there is no entity
        return nullptr;
    }

    auto object = std::move(*itr);
    objects_.erase(itr);
    return object;
}

} // namespace gameSystem
