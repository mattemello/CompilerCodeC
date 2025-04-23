#include <cstdlib>
#include <stdio.h>
#include <string>
#include "analysis.h"

constexpr unsigned int str2int(const char* str, int h = 0){
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

bool isNumber(std::string token);

bool controlValuePosition(std::string txt, int position){
    if(txt[position] == ' '){
        return false;
    }
}

size_t searchSeparator(std::string text) {
    for(size_t i = 0; i < text.length(); i++){
        if((text[i] < 'a' || text[i] > 'z')&& (text[i] < '0' || text[i] > '9') && (text[i] < 'A' || text[i] > 'Z')){
            return i;
        }
    }

    return text.length();
}

ReturnValue analysis(std::string text) {
    int dimensionToken = 3;
    Tokens* token = (Tokens*)malloc(sizeof(Tokens) * (dimensionToken));
    int count = 0; 

    while(text != "\0") {
        if(count >= dimensionToken) {
            dimensionToken = dimensionToken + 8;
            token = (Tokens*)realloc(token, (sizeof(Tokens)*(dimensionToken)));

        }
        size_t position = searchSeparator(text);
        if(position == 0){
            //todo: control here if the position is a space or other 
            text = text.substr(position+1, text.length());
            continue;
        }
    
        const std::string thisToken = text.substr(0, position); 
        if(position >= text.length()){
            text = "\0";
        }else{
            text = text.substr(position+1, text.length());
        }

        if(isNumber(thisToken)){
            token[count].Token = 0;
            token[count].Value = thisToken;
        }

        switch (str2int(thisToken.c_str())) {
            case str2int("assing"):
                token[count].Value = thisToken;
                token[count].Token = 259;
            break;
            case str2int("to"):
                token[count].Value = thisToken;
                token[count].Token = 260;
            break;
            case str2int("if"):
                token[count].Value = thisToken;
                token[count].Token = 261;
            break;
            case str2int("else"):
                token[count].Value = thisToken;
                token[count].Token = 262;
            break;
            case str2int("do"):
                token[count].Value = thisToken;
                token[count].Token = 263;
            break;
            case str2int("for"):
                token[count].Value = thisToken;
                token[count].Token = 264;
            break;
            case str2int("begin"):
                token[count].Value = thisToken;
                token[count].Token = 265;
            break;
            case str2int("end"):
                token[count].Value = thisToken;
                token[count].Token = 266;
            break;
            case str2int("print"):
                token[count].Value = thisToken;
                token[count].Token = 267;
            break;
            case str2int("read"):
                token[count].Value = thisToken;
                token[count].Token = 2628;
            break;
            default:
                //todo: control if it can be a Id or is a simbol
            break;
        }

        //todo: control the position

        count++;
    }

    ReturnValue value;
    value.token = token;
    value.dimensioArray = dimensionToken;

    return value;
}

bool isNumber(std::string token) {
    for(int i = 0; i < token.length(); i++){
        if(token[i] < '0' || token[i] > '9') 
            return false;
    }
        

    return true;
}
