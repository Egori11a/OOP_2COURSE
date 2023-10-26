#include <iostream>
#include <string>
#include "func.h"


void function_replace(std::string& text, int n, char old_value, char new_value)
{
int count_old_value;
    for(int i=0;i<text.length(); i++){
        if(text[i]==old_value){
            count_old_value++;
        }
    }
    if(n<=0 || n>count_old_value){
        std::cout<<text<<std::endl;
    }
    count_old_value=0;
    for(int i=0;i<text.length(); i++){
        if(text[i]==old_value){
            count_old_value++;
        }
        if(count_old_value%n==0 && count_old_value!=0){
            text[i]=new_value;
            count_old_value=0;
        }  
    }

}