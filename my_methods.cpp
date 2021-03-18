#include "my_methods.h"

#include <algorithm>

void DeleteSpaces(std::string& str) {
    while (str.size() && str.back() == ' ')
        str.pop_back();
    std::reverse(str.begin(), str.end());
    while (str.size() && str.back() == ' ')
        str.pop_back();
    std::reverse(str.begin(), str.end());
}

int IsValidName(const std::string& str) {
    if (str.empty())
        return 1;
    if (str.size() > 20)
        return 2;
    for (const auto c : str) {
        if (!IsLetter(c))
            return 3;
    }
    return 0;
}

bool IsLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool IsDigit(char c) {
    return c >= '0' && c <= '9';
}

QString GenerateErrorMessage(const std::string& str, int code) {
    switch (code) {
        case 1 : return QString::fromStdString(str + " is empty");
        case 2 : return QString::fromStdString(str + " size is more than 20 characters");
        case 3 : return QString::fromStdString(str + " consists wrong character. Only English letters");
    }
}

size_t CalculateTapFactor(size_t& clicks_per_prev_second, size_t& seconds_in_row) {
    size_t tap_factor;
    if (clicks_per_prev_second)
        seconds_in_row++;
    else
        seconds_in_row = 0;

    if (seconds_in_row < 5)
        tap_factor = 1;
    else if (seconds_in_row < 20)
        tap_factor = 2;
    else if (seconds_in_row < 40)
        tap_factor = 3;
    else if (seconds_in_row < 60)
        tap_factor = 4;
    else if (seconds_in_row < 300)
        tap_factor = 5;
    else tap_factor = 100;

    clicks_per_prev_second = 0;
    return tap_factor;
}
