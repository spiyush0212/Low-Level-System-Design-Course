#pragma once

#include <string>
#include "MealFactory.h"
#include "MultigrainMcAllo.cpp"
#include "MultigrainMcVeggie.cpp"
#include "MultigrainMcPaneer.cpp"
#include "PlainGarlicBread.cpp"
#include "CheeseGarlicBread.cpp"

using namespace std;

class BurgerSinghMealFactory : public MealFactory {
public:
    Burger* createBurger(const string& burgerType) override {
        if (burgerType == "McAllo")
            return new MultigrainMcAllo();
        if (burgerType == "McVeggie")
            return new MultigrainMcVeggie();
        if (burgerType == "McPaneer")
            return new MultigrainMcPaneer();
        return nullptr;
    }

    GarlicBread* createGarlicBread(const string& garlicBreadType) override {
        if (garlicBreadType == "Plain")
            return new PlainGarlicBread();
        if (garlicBreadType == "Cheese")
            return new CheeseGarlicBread();
        return nullptr;
    }
};
