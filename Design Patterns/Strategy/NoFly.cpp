#include <iostream>
#include "IFlyable.h"

using namespace std;

class NoFly : public IFlyable {
public:
    void fly() override {
        cout << "Can not fly!!!" << "\n";
    }
};
