#include "DamageTemplate.hpp"

namespace gameSystem {

unsigned DamageTemplate::getPower(const oxEngine::Vector2i& point) const {
    int R = point.magnitudeSquared();
    if (type_ == DamageType::beam){
        if (R < radius_ * radius_) {
            return power_;
        }
    } else if (type_ == DamageType::deep_crater) {
        if (R < radius_ * radius_) {
            return power_ * static_cast<unsigned>(std::sqrt(static_cast<float>(radius_*radius_ - R)));
        }
    } else if (type_ == DamageType::shallow_crater) {
        if (R < radius_ * radius_) {
            return power_ * (static_cast<unsigned>(std::sqrt(static_cast<float>(radius_*radius_*4 - R))) - radius_);
        }
    }
    return 0;
}

} // using gameSystem
