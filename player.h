#ifndef PLAYER_H
#define PLAYER_H

#include "skin.h"
#include "big_integer.h"
#include "boost.h"

#include <iostream>

class Player {
public:
    Player(const std::string& name, const std::string& surname);

    BigInteger getPoints() const;
    BigInteger getPerSecond() const;
    BigInteger getPerClick() const;
    size_t getTapFactor() const;
    Skin& getSkin();

    std::string FilePath() const;
    void Read();
    void Write() const;

    void Click();
    void GivePerSecond();

    void BuyClickBoost();
    void BuyPassiveBoost(size_t index);

    QString PassiveBoostInfo(size_t index);
    QString ClickBoostInfo();

    BigInteger getBoostPrice(size_t index);

private:
    std::string name_;
    std::string surname_;

    BigInteger points_;
    BigInteger per_second_;
    BigInteger per_click_ = BigInteger(1);
    size_t tap_factor;
    size_t clicks_per_prev_second, seconds_in_row;
    Skin skin_ = Skin("coin");

    ClickBoost click_boost;
    std::vector<PassiveBoost> passive_boost;
};

#endif // PLAYER_H
