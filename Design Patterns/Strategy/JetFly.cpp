#include <iostream>
#include "IFlyable.h"

using namespace std;

class JetFly : public IFlyable {
public:
    void fly() override {
        cout << "Flies using jet powered fly!!!" << "\n";
    }
};
