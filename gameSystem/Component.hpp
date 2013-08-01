#ifndef GAMESYSTEM_COMPONENT_HPP
#define GAMESYSTEM_COMPONENT_HPP

#include <string>

namespace gameSystem {

enum ComponentType
{
    crew_quarters,
    life_support,
    life_boats,
    supply_hold,
    repair_hold,
    repair_station,
    engine,
    magazine,
    weapon,
    turret,
    fire_system,
    shield,
    capacitor_bank,
    power_plant,
    active_sensor,
    pasive_sensor
};

class Component
{
    std::string componentId_;

    ComponentType type_;
    float mass_;
    float size_;

public:
    Component(const std::string& componentId);

    void loadComponent();

    const std::string& getComponentId() const ;
    ComponentType getType() const;
    float getMass() const;
    float getSize() const;

    unsigned damageComponent(unsigned damage);
};

} // namespace gameSystem

#endif // GAMESYSTEM_COMPONENT_HPP
