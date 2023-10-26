#pragma once // говорит компилятору что данный файл должен быть включен только один раз

#include <string>

void function_replace(std::string& text, int n, char old_value, char new_value);