#pragma once

#include "IDecorator.h"
#include <iostream>
#include <string>

using namespace std;

class SwimDecorator : public IDecorator {
public:
    SwimDecorator(ICharacter* ch) : IDecorator(ch) {}
    
    void getAbilities() override {
        IDecorator::character->getAbilities();
        cout << " + Swim ";
    }
};