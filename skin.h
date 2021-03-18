#ifndef SKIN_H
#define SKIN_H

#include <iostream>
#include <vector>
#include <map>

static std::map<std::string, std::string> POINTS_NAMES {
    {"coin", "coins"},
    {"шайба", "шайб"},
    {"heart", "сердечек"},
};
static std::map<std::string, std::vector<std::string>> BOOST_NAMES {
    {"coin", {"клик бустик", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}},
    {"шайба", {"докинуться" ,"вкинуть снюс", "двойной вкид", "вкидмак 3", "передать вторяк без рук", "5", "6", "7", "8", "9", "10"}},
    {"heart", {"клик бустик", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}},
};
static std::map<std::string, std::string> PICS {
    {"coin", "coin.png"},
    {"шайба", "шайба.png"},
    {"heart", "heart.png"},
};

class Skin {
public:
    explicit Skin(const std::string& skin);

    std::string getSkinName() const;
    std::string getBoostName(size_t number) const;
    std::string getClickBoostName() const;
    std::string getPointsName() const;
    std::string getPic() const;

    void Change(const std::string& skin);

private:
    std::string skin_;
};

#endif // SKIN_H
