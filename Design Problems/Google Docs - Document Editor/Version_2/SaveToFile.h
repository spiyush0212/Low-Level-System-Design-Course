#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Persistence.h"
using namespace std;

class SaveToFile : public Persistence {
private:
    string fileName_;

public:
    explicit SaveToFile(const string& fileName = "document1.txt") : fileName_(fileName) {}

    void save(const string& data) override {
        ofstream file(fileName_);
        file << data << "\n";
        file.close();

        cout << "*****\n";
        cout << "Document has been saved to local device!\n";
        cout << "*****\n";
    }
};
