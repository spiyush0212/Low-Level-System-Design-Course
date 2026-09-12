#include <iostream>
#include "ComputerFacade.h"

using namespace std;

int main() {
    ComputerFacade* cf = new ComputerFacade();

    cf->run();
    
    return 0;
}