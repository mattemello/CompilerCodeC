#include <cstddef>
#include <stdio.h>
#include <string>
#include "analysis.h"

int prova() {
    return 1;
}

bool isNumber(std::string token);

std::string analysis(std::string text) {
    std::string* token;

    while(text != "\0") {
        size_t position = text.find(" ");
        std::string thisToken = text.substr(0, position); 

        if(isNumber(thisToken)){
            return thisToken;
        }
        return "";
    }
    return "";
}

bool isNumber(std::string token) {
    if(token[0] >= '0' && token[0] <= '9') {
        return true;
    }

    return false;
}
