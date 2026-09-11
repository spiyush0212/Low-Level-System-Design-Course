#pragma once

#include <iostream>
#include <string>
#include "Persistence.h"
using namespace std;

class SaveToDB : public Persistence {
public:
    void save(const string& data) override {
        cout << "Save to DB\n";
    }
};
