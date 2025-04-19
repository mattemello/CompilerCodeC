#include <iostream>
#include <string>
#include "analysis.h"

int main() {
    std::string stry = "(34+26( - (2+15-( 27";
    ReturnValue res = analysis(stry);

    Tokens* retV = res.token;
    for(int i = 0; i < res.dimensioArray; i++){
        std::cout << retV[i].Token << " " << retV[i].Value << " i: " << i << std::endl;
    }
    
    return 0;
}
