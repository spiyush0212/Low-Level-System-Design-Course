#pragma once

#include <iostream>

using namespace std;

class IFlyable {
public:
    virtual void fly() = 0;
    virtual ~IFlyable() {}
};