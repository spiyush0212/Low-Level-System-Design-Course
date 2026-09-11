#pragma once

#include "IDecorator.h"
#include <iostream>
#include <string>

using namespace std;

class RunDecorator : public IDecorator {
public:
    RunDecorator(ICharacter* ch) : IDecorator(ch) {}
    
    void getAbilities() override {
        IDecorator::character->getAbilities();
        cout << " + Run ";
    }
};