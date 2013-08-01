#ifndef GAMESYSTEM_MAP_HPP
#define GAMESYSTEM_MAP_HPP

#include "../Rules.hpp"

#include <vector>
#include <memory>

namespace gameSystem {

class Object;

class Map
{
    const Rules& ruleSheet_;

    std::vector<std::unique_ptr<Object>> objects_;
    int systemNumber_;

public:
    Map(const Rules& ruleSheet, int systemNumber);

    void updateSystem(float timeInterval);

    template <typename T, typename... Args>
    T* createSystemObject(Args&&... args);
    void insertSystemObject(std::unique_ptr<Object>&& obj);
    std::unique_ptr<Object> releaseObject(Object* obj);
};

template <typename T, typename... Args>
T* Map::createSystemObject(Args&&... args) {
    static_assert(std::is_base_of<Object, T>::value,
                  "Type must derive from Object");

    T* obj = new T(this, std::forward<Args>(args)...);
    objects_.emplace_back(obj);
    return obj;
}

} // namespace gameSystem

#endif // GAMESYSTEM_OBJECT_HPP
