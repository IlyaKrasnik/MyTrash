#ifndef MY_METHODS_H
#define MY_METHODS_H

#include <iostream>
#include <QString>

void DeleteSpaces(std::string& str);
int IsValidName(const std::string& str);

bool IsLetter(char c);
bool IsDigit(char c);

size_t CalculateTapFactor(size_t& clicks_per_prev_second, size_t& seconds_in_row);
QString GenerateErrorMessage(const std::string& str, int code);

#endif // MY_METHODS_H
