#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include "analysis.h"


constexpr unsigned int str2int(const char* str, int h = 0){
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

Tokens controlString(std::string);
Tokens controlSimbol(char);

bool isNumber(std::string token);

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
        std::cout << text << std::endl;
        if(count >= dimensionToken) {
            dimensionToken = dimensionToken + 8;
            token = (Tokens*)realloc(token, (sizeof(Tokens)*(dimensionToken)));

        }

        size_t position = searchSeparator(text);

        // todo: control for the operator

        if(position == 0){
            if(text[position] != ' '){
                switch (text[position]) {
                    case ':':
                        if(text[position+1] != '='){
                            //ERROR
                        }
                        position++;
                        if(text[position+1] == '='){
                            //ERROR
                        }
                        token[count].Token = 269;
                        token[count].Value = (char*)malloc(sizeof(char)*2);
                        token[count].Value = (char*)":=";
                    break;
                    case '|':
                        if(text[position+1] != '|'){
                            //ERROR
                        }
                        position++;
                        if(text[position+1] == '|'){
                            //ERROR
                        }
                        token[count].Token = 270;
                        token[count].Value = (char*)malloc(sizeof(char)*2);
                        token[count].Value = (char*)"||";
                        break;
                    case '&':
                        if(text[position+1] != '&'){
                            //ERROR
                        }
                        position++;
                        if(text[position+1] == '&'){
                            //ERROR
                        }
                        token[count].Token = 271;
                        token[count].Value = (char*)malloc(sizeof(char)*2);
                        token[count].Value = (char*)"&&";
                        break;
                    case '<':
                        if(text[position+1] == '=' || text[position+1] == '>'){
                            token[count].Value = text.substr(position, position+1).c_str();
                            position++;
                        }else{
                            token[count].Value = "<";
                        }
                        token[count].Token = 258;
                    break;
                    case '>':
                        if(text[position+1] == '='){
                            token[count].Value = text.substr(position, position+1);
                            position++;
                        }else{
                            token[count].Value = ">";
                        }
                        token[count].Token = 258;
                    break;
                    case '=':
                        if(text[position+1] == '='){
                            token[count].Value = text.substr(position, position+1);
                            position++;
                        }else{
                            //ERROR
                        }
                        token[count].Token = 258;
                    break;
                    default:
                        Tokens tt = controlSimbol(text[position]);
                        token[count].Token = tt.Token;
                        break;

                }
                count++;

            }


            position++;
            text = text.substr(position, text.length());
            continue;
        }
    
        const std::string thisToken = text.substr(0, position); 

        if(isNumber(thisToken)){
            token[count].Token = 256;
            token[count].Value = thisToken.c_str;
        }else{
            token[count] = controlString(thisToken);
        }
        count++;

        if(text[position] != ' '){
            switch (text[position]) {
                case ':':
                    if(text[position+1] != '='){
                        //ERROR
                    }
                    token[count].Token = 269;
                    token[count].Value = ":=";
                    position++;
                    break;
                case '|':
                    if(text[position+1] != '|'){
                        //ERROR
                    }
                    token[count].Token = 270;
                    token[count].Value = "||";
                    position++;
                    break;
                case '&':
                    if(text[position+1] != '&'){
                        //ERROR
                    }
                    token[count].Token = 271;
                    token[count].Value = "&&";
                    position++;
                    break;
                case '<':
                    if(text[position+1] == '=' || text[position+1] == '>'){
                        token[count].Value = text.substr(position, position+1);
                        position++;
                    }else{
                        token[count].Value = "<";
                    }
                    token[count].Token = 258;
                    break;
                case '>':
                    if(text[position+1] == '='){
                        token[count].Value = text.substr(position, position+1);
                        position++;
                    }else{
                        token[count].Value = ">";
                    }
                    token[count].Token = 258;
                    break;
                case '=':
                    if(text[position+1] == '='){
                        token[count].Value = text.substr(position, position+1);
                        position++;
                    }else{
                        //ERROR
                    }
                    token[count].Token = 258;
                    break;
                default:
                    Tokens tt = controlSimbol(text[position]);
                    token[count].Token = tt.Token;
                    break;
            }

        }

        if(position >= text.length() || text[position] == '\0'){
            break;
        }else{
            text = text.substr(position+1, text.length());
        }

        count++;
    }

    if(count >= dimensionToken) {
        dimensionToken = dimensionToken + 1;
        token = (Tokens*)realloc(token, (sizeof(Tokens)*(dimensionToken)));
    }

    token[count].Token = -1;
    token[count].Value = "EOF";
    count++;

    ReturnValue value;
    value.token = token;
    value.dimensioArray = count;


    return value;
}

bool isNumber(std::string token) {
    for(int i = 0; i < token.length(); i++){
        if(token[i] < '0' || token[i] > '9') 
            return false;
    }
        

    return true;
}

Tokens controlSimbol(char simb) {
    Tokens token;
    std::string voidNull = "";

    switch (simb) {
        case '!':
            token.Token = 33;
            break;
        case '(':
            token.Token = 40;
            break;
        case ')':
            token.Token = 41;
            break;
        case '[':
            token.Token = 91;
            break;
        case ']':
            token.Token = 93;
            break;
        case '{':
            token.Token = 123;
            break;
        case '}':
            token.Token = 125;
            break;
        case '+':
            token.Token = 43;
            break;
        case '-':
            token.Token = 45;
            break;
        case '*':
            token.Token = 42;
            break;
        case '/':
            token.Token = 47;
            break;
        case ';':
            token.Token = 59;
            break;
        case ',':
            token.Token = 44;
            break;

        default:
            //ERROR
        break;
    }

    return token;
}

Tokens controlString(std::string thisToken){
    Tokens token;

    switch (str2int(thisToken.c_str())) {
        case str2int("assing"):
            token.Value = thisToken.c_str;
            token.Token = 259;
            break;
        case str2int("to"):
            token.Value = thisToken.c_str;
            token.Token = 260;
            break;
        case str2int("if"):
            token.Value = thisToken.c_str;
            token.Token = 261;
            break;
        case str2int("else"):
            token.Value = thisToken.c_str;
            token.Token = 262;
            break;
        case str2int("do"):
            token.Value = thisToken.c_str;
            token.Token = 263;
            break;
        case str2int("for"):
            token.Value = thisToken.c_str;
            token.Token = 264;
            break;
        case str2int("begin"):
            token.Value = thisToken.c_str;
            token.Token = 265;
            break;
        case str2int("end"):
            token.Value = thisToken.c_str;
            token.Token = 266;
            break;
        case str2int("print"):
            token.Value = thisToken.c_str;
            token.Token = 267;
            break;
        case str2int("read"):
            token.Value = thisToken.c_str;
            token.Token = 2628;
            break;
        default:
            //todo: control if it can be a Id or is a simbol
            break;
    }

    return token;
}
