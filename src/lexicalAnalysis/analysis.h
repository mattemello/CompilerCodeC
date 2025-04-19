#ifndef ANALYSIS_H100
#define ANALYSIS_H100

#include <string>

typedef struct  {
    int Token;
    std::string Value;
}Tokens;

typedef struct{
    int dimensioArray;
    Tokens* token;
}ReturnValue;

ReturnValue analysis(std::string);

#endif
