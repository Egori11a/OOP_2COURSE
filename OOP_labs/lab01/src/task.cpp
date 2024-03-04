#include <iostream>
#include "../include/task.hpp"
#include <string>

std::string function_replace(const std::string& text, int n, char old_value, char new_value)
{
    int old_value_count = 0;
    for (size_t i = 0; i < text.length(); ++i) {
            if (text[i] == old_value) {
                old_value_count += 1;
            }
    }

    if (n <= 0 || n > old_value_count) {
        return text;
    }
    else if(old_value_count = 0){
        return text;
    }
    else{
        std::string modified_text = text;
    // Счетчик для отслеживания n-ого вхождения old_value
        int count = 0;

        for (size_t i = 0; i < modified_text.length(); ++i) {
            if (modified_text[i] == old_value) {
                count += 1;
                if (count == n) {
                    modified_text[i] = new_value;
                    count = 0;
                }
            }
        }
        return modified_text;
    }   
}