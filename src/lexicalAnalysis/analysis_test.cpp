#include <iostream>
#include <string>
#include "analysis.h"

int main() {
    std::string stry = "&&";
    ReturnValue res = analysis(stry);

    Tokens* retV = res.token;
    std::cout << "firs:" << std::endl;
    for(int i = 0; i < res.dimensioArray; i++){
        std::cout << retV[i].Token << " " << retV[i].Value << " |";
    }
    std::cout << "---------" << std::endl;
    std::cout << "" << std::endl;

    stry = "(34+26( - (2+15-( 27";
    res = analysis(stry);

    retV = res.token;
    std::cout << "here" << std::endl;
    for(int i = 0; i < res.dimensioArray; i++){
        std::cout << retV[i].Token << " " << retV[i].Value << " i: " << i << std::endl;
    }
    
    return 0;
}
