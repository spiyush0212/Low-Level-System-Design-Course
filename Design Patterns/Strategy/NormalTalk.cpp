#include <iostream>
#include "ITalkable.h"

using namespace std;

class NormalTalk : public ITalkable {
public:
    void talk() override {
        cout << "Talks using actual mouth" << "\n";
    }
};