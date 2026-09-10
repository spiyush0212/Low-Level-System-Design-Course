#pragma once

#include <string>
#include "Burger.h"

using namespace std;

class BurgerFactory {
public:
    virtual Burger* createBurger(const string& burgerType) = 0;
    virtual ~BurgerFactory() {}
};