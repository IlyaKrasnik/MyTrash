#include "skin.h"

Skin::Skin(const std::string& skin) : skin_(skin) {}

std::string Skin::getSkinName() const {
    return skin_;
}

std::string Skin::getBoostName(size_t number) const {
    return BOOST_NAMES.at(skin_)[number + 1];
}

std::string Skin::getPointsName() const {
    return POINTS_NAMES.at(skin_);
}

std::string Skin::getClickBoostName() const {
    return BOOST_NAMES.at(skin_)[0];
}

std::string Skin::getPic() const {
    return PICS.at(skin_);
}

void Skin::Change(const std::string& skin) {
    skin_ = skin;
}

