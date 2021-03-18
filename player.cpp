#include "player.h"
#include "my_methods.h"

#include <iostream>
#include <fstream>

Player::Player(const std::string& name, const std::string& surname) : name_(name), surname_(surname) {
    for (int i = 0; i < 10; i++)
        passive_boost.emplace_back(i);
    Read();
    tap_factor = 1;
    clicks_per_prev_second = 0;
    seconds_in_row = 0;
}

BigInteger Player::getPoints() const { return points_; }
BigInteger Player::getPerSecond() const { return per_second_; }
BigInteger Player::getPerClick() const { return per_click_; }
size_t Player::getTapFactor() const { return tap_factor; }
Skin& Player::getSkin() { return skin_; }

std::string Player::FilePath() const {
    return "database/" + name_ + "_" + surname_ + ".txt";
}

void Player::Read() {
  std::ifstream is(FilePath());
  if (is.is_open()) {
    std::string x;
    is >> x >> x;
    points_ = BigInteger(x);
    is >> x >> x;
    per_click_ = BigInteger(x);
    is >> x >> x;
    per_second_ = BigInteger(x);
    is >> x >> x;
    skin_.Change(x);

    for (size_t i = 0; i < passive_boost.size(); i++) {
        is >> x;
        is >> passive_boost[i];
    }

    is >> x;
    is >> click_boost;

  }
  is.close();
}

void Player::Write() const {
    std::ofstream os(FilePath());
    os << "points: " << points_.ToLongString() << "\nper_click: " << per_click_.ToLongString()
       << "\nper_second: " << per_second_.ToLongString() << "\nskin: " << skin_.getSkinName() << "\n";

    for (int i = 0; i < passive_boost.size(); ++i) {
        os << "boost" << std::to_string(i + 1) << "\n";
        os << passive_boost[i];
    }

    os << "click_boost:" << "\n";
    os << click_boost;

    os.close();
}

void Player::Click() {
    points_ += per_click_ * tap_factor;
    clicks_per_prev_second++;
}

void Player::BuyPassiveBoost(size_t index) {
    Boost& boost = passive_boost[index];
    if (points_ >= boost.getPrice()) {
        points_ -= boost.getPrice();
        per_second_ += boost.UpdateForLevel();
    }
}

void Player::BuyClickBoost() {
    if (points_ >= click_boost.getPrice()) {
        points_ -= click_boost.getPrice();
        per_click_ += click_boost.UpdateForLevel();
    }
}

void Player::GivePerSecond() {
    points_ += per_second_;
    tap_factor = CalculateTapFactor(clicks_per_prev_second, seconds_in_row);
}

QString Player::PassiveBoostInfo(size_t index) {
    return QString::fromStdString(skin_.getBoostName(index)) + ".\n"
         + passive_boost[index].TextForButton();
}

QString Player::ClickBoostInfo() {
    return QString::fromStdString(skin_.getClickBoostName()) + ".\n"
            + click_boost.TextForButton();
}

BigInteger Player::getBoostPrice(size_t index) {
    if (index == 0)
        return click_boost.getPrice();
    return passive_boost[index - 1].getPrice();
}
