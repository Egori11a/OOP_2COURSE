#include "include/task.hpp"
#include <iostream>
#include <string>

int main() {

    std::cout << "Введите строку text: ";
    std::string text;
    std::getline(std::cin, text);

    // Ввод символа old_value
    std::cout << "Введите символ old_value: ";
    char old_value;
    std::cin >> old_value;

    // Ввод символа new_value
    std::cout << "Введите символ new_value: ";
    char new_value;
    std::cin >> new_value;

    // Ввод номера n
    std::cout << "Введите число n: ";
    int n;
    std::cin >> n;

    std::string result = function_replace(text, n, old_value, new_value);
    std::cout<<result<<std::endl;


    return 0;
}