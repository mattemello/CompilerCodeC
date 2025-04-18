#ifndef ANALYSIS_H100
#define ANALYSIS_H100

#include <string>

typedef struct  {
    int Token;
    std::string Value;
}Tokens;

Tokens* analysis(std::string);

#endif
