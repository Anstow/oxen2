#include "Component.hpp"

namespace gameSystem {

Component::Component(const std::string& componentId)
    : componentId_(componentId)
{
    loadComponent();
}

void Component::loadComponent()
{
    // TODO: load the component
}

const std::string& Component::getComponentId() const {
    return componentId_;
}

ComponentType Component::getType() const {
    return type_;
}

float Component::getMass() const {
    return mass_;
}

float Component::getSize() const {
    return size_;
}

unsigned Component::damageComponent(unsigned damage) {
    // TODO: damage the component
    return 0;
}

} // namespace gameSystem
