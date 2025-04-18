#include <iostream>
#include <stdio.h>
#include <string>
#include "analysis.h"

int prova() {
    return 1;
}

constexpr unsigned int str2int(const char* str, int h = 0){
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


bool isNumber(std::string token);

Tokens* analysis(std::string text) {
    std::string enum {
        assing = 0
    }type;

    Tokens* token;
    token = (Tokens*)malloc(sizeof(Tokens) * 3);
    int count = 0; 

    while(text != "\0") {
        size_t position = text.find(" ");
    
        if(position > text.length()){
            position = text.length();
        }

        const std::string thisToken = text.substr(0, position); 
        text = text.substr(position+1, text.length());

        std::cout<< thisToken << "  " << position << " " << count << std::endl;
        if(isNumber(thisToken)){
            token[count].Token = 0;
            token[count].Value = thisToken;
        }

        switch (str2int(thisToken)) {
            case str2int(assing):
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case str2int(ifV):
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case str2int(elseV):
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case str2int(doV):
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
        }

        count++;
    }
    return token;
}

bool isNumber(std::string token) {
    for(int i = 0; i < token.length(); i++)
        if(token[i] < '0' && token[i] > '9') 
            return false;
        

    return true;
}
