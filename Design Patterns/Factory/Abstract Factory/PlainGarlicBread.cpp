#pragma once

#include "GarlicBread.h"

class PlainGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Plain Garlic Bread: No Cheese" << endl;
    }
};
