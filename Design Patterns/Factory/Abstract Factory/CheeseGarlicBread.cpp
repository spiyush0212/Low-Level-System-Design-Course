#pragma once

#include "GarlicBread.h"

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Cheese Garlic Bread: With Cheese" << endl;
    }
};
