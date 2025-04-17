#ifndef ANALYSIS_H100
#define ANALYSIS_H100

#include <string>

struct Tokens {
    int Token;
    std::string Value;
};

struct Tokens* analysis(std::string);

#endif
