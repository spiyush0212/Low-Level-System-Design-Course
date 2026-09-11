#pragma once

#include <string>
using namespace std;

class Persistence {
public:
    virtual ~Persistence() = default;
    virtual void save(const string& data) = 0;
};
