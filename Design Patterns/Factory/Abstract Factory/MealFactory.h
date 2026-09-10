#pragma once

#include <string>
#include "Burger.h"
#include "GarlicBread.h"

using namespace std;

class MealFactory {
public:
    virtual Burger* createBurger(const string& burgerType) = 0;
    virtual GarlicBread* createGarlicBread(const string& garlicBreadType) = 0;
    virtual ~MealFactory() = default;
};
