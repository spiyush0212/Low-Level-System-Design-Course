#pragma once

#include "ICharacter.h"
#include <string>
#include <iostream>

using namespace std;

class Mario : public ICharacter {
public:
    Mario(const string& n) : name(n) {}

    void getAbilities() override {
        cout << name << " can walk";
    }

private:
    string name;
};