#ifndef GAMESYSTEM_OBJECT_HPP
#define GAMESYSTEM_OBJECT_HPP

#include "../Rules.hpp"
#include "Map.hpp"
#include "WeaponDamage.hpp"

#include "../engine/utility/Vector3.hpp"

#include <string>
#include <memory>
#include <random>

namespace gameSystem {

using Vector3i64 = oxEngine::Vector3<int64_t>;

class Object
{  
    const Rules& ruleSheet_;
    std::minstd_rand0 randomGenerator;

    Map* parentMap_;

    Vector3i64 position_;
    Vector3i64 velocity_;

    float mass_;
    float size_;

    std::string type_;
    unsigned owner_ = 0;

    friend void Map::insertSystemObject(std::unique_ptr<Object>&& obj);

protected:
    void setPosition(const Vector3i64& pos);
    void setVelocity(const Vector3i64& vel);

    void setMass(float mass);
    void setSize(float size);

    const Rules& getRules() const;
    std::minstd_rand0& getRandom();

public:
    Object(const Rules& ruleSheet, unsigned randomSeed, Map* parentMap, Vector3i64 pos, Vector3i64 vel, const std::string& type);

    virtual void updateObject(float timeInterval) = 0;

    virtual void hitByObject(const Object& obj) = 0;
    virtual void hitByWeapon(const WeaponDamage& weaponDamage) = 0;

    const Vector3i64& getPosition();
    const Vector3i64& getVelocity();

    float getMass();
    float getSize();

    std::string getType();
    void setOwner(unsigned owner);
    unsigned getOwner();
};

inline void Object::setPosition(const Vector3i64& pos) {
    position_ = pos;
}

inline void Object::setVelocity(const Vector3i64& vel) {
    velocity_ = vel;
}

inline const Vector3i64& Object::getPosition() {
    return position_;
}

inline const Vector3i64& Object::getVelocity() {
    return velocity_;
}

inline void Object::setMass(float mass) {
    mass_ = mass;
}

inline void Object::setSize(float size) {
    size_ = size;
}

inline const Rules& Object::getRules() const {
    return ruleSheet_;
}

inline std::minstd_rand0& Object::getRandom() {
    return randomGenerator;
}

inline float Object::getMass() {
    return mass_;
}

inline float Object::getSize() {
    return size_;
}

inline std::string Object::getType() {
    return type_;
}

inline void Object::setOwner(unsigned owner) {
    owner_ = owner;
}

inline unsigned Object::getOwner() {
    return owner_;
}

} // namespace gameSystem

#endif // GAMESYSTEM_OBJECT_HPP
