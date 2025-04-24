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
    std::cout << std::endl << "---------" << std::endl;
    std::cout << "" << std::endl;

    stry = "else 5 == print < end";
    res = analysis(stry);

    retV = res.token;
    for(int i = 0; i < res.dimensioArray; i++){
        std::cout << retV[i].Token << " " << retV[i].Value << " i: " << i << std::endl;
    }
    
    return 0;
}
