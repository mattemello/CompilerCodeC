<<<<<<< HEAD
#include <cstddef>
#include <iostream>
=======
#include <iostream>
#include <stdio.h>
>>>>>>> a4d60d4 (understand)
#include <string>
#include "analysis.h"

int prova() {
    return 1;
}

bool isNumber(std::string token);

struct Tokens* analysis(std::string text) {
    struct Tokens* token;
    token = (Tokens*)malloc(sizeof(Tokens) * 3);
    int count = 0; 

    while(text != "\0") {
        size_t position = text.find(" ");
    
        if(position > text.length()){
            position = text.length();
        }

        std::string thisToken = text.substr(0, position); 
        text = text.substr(position+1, text.length());

        std::cout<< thisToken << "  " << position << " " << count << std::endl;
        if(isNumber(thisToken)){
            token[count].Token = 0;
            token[count].Value = thisToken;
        }
        count++;
    }
    return token;
}

bool isNumber(std::string token) {
    if(token[0] >= '0' && token[0] <= '9') {
        return true;
    }

    return false;
}
