#include <iostream>
#include "ITalkable.h"

using namespace std;

class NoTalk : public ITalkable {
public:
    void talk() override {
        cout << "Can not talk!!!" << "\n";
    }
};