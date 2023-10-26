#include <iostream>
#include "func.h"

int main() {
    std::string text;
    std::cout<<"Введите строку: ";
    std::cin>>text;

    int n;
    std:: cout<<"Введите номер символа: ";
    std::cin>>n;

    char old_value;     
    std::cout<<"Введите old_value: ";
    std::cin>>old_value;
    
    char new_value;
    std::cout<<"Введите new_value: ";    
    std::cin>>new_value;
    function_replace(text, n, old_value, new_value);
    std::cout<<text<<std::endl;


    return 0;
}