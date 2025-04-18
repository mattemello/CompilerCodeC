#include <iostream>
#include <stdio.h>
#include <string>
#include "analysis.h"

int main() {
    std::string stry = "12 34 56";
    Tokens* res = analysis(stry);

    for(int i = 0; i < 3; i++){
        std::cout << res[i].Token << " " << res[i].Value << " i: " << i << std::endl;
    }
    
    return 0;
}
