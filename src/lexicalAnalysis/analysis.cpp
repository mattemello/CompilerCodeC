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

const std::string assing = "assing", ifV = "if", elseV = "else", doV = "do";

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

        const std::string thisToken = text.substr(0, position); 
        text = text.substr(position+1, text.length());

        std::cout<< thisToken << "  " << position << " " << count << std::endl;
        if(isNumber(thisToken)){
            token[count].Token = 0;
            token[count].Value = thisToken;
        }

        switch (thisToken==) {
            case assing:
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case ifV:
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case elseV:
                token[count].Value = thisToken;
                token[count].Token = 1;
            break;
            case doV:
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
