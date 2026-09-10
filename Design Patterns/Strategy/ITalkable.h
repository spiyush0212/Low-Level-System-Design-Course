#pragma once

#include <iostream>

using namespace std;

class ITalkable {
public:
    virtual void talk() = 0;
    virtual ~ITalkable() {}
};