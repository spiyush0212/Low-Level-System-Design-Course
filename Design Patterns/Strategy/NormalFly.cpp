#include <iostream>
#include "IFlyable.h"

using namespace std;

class NormalFly : public IFlyable {
public:
    void fly() override {
        cout << "Flies using normal flying method" << "\n";
    }
};
