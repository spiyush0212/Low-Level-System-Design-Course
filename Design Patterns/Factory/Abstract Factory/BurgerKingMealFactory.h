#pragma once

#include <string>
#include "MealFactory.h"
#include "McAllo.cpp"
#include "McVeggie.cpp"
#include "McPaneer.cpp"
#include "PlainGarlicBread.cpp"
#include "CheeseGarlicBread.cpp"

using namespace std;

class BurgerKingMealFactory : public MealFactory {
public:
    Burger* createBurger(const string& burgerType) override {
        if (burgerType == "McAllo")
            return new McAllo();
        if (burgerType == "McVeggie")
            return new McVeggie();
        if (burgerType == "McPaneer")
            return new McPaneer();
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
