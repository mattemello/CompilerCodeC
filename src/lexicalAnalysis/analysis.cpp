#include <cstddef>
#include <iostream>
#include <string>
#include "analysis.h"

int prova() {
    return 1;
}

bool isNumber(std::string token);

std::string analysis(std::string text) {
    std::string token;

    while(text != "\0") {
        size_t position = text.find(" ");
        if(position == 0 || position > text.length()) {
            position = text.length();
        }

        std::string thisToken = text.substr(0, position); 

            text = text.substr(position+1, text.length());

        if(isNumber(thisToken)){
            token += thisToken;
        }
        std::cout << position << std::endl;
    }
    return token;
}

bool isNumber(std::string token) {
    if(token[0] >= '0' && token[0] <= '9') {
        return true;
    }

    return false;
}
