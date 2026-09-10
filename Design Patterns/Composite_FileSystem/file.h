#pragma once

#include <iostream>
#include <string>
#include "FileSystemItem.h"

using namespace std;

class File : public FileSystemItem {
private:
    string name;
    int size;

public:
    File(const string& n, const int s) {
        this->name = n;
        this->size = s;
    }

    void ls() override {
        cout << getName() << "\n";
    }

    void tree() override {
        cout << getName() << "\n";
    }

    FileSystemItem* cd(const string& dir) override {
        return nullptr;
    }

    string getName() override {
        return name;
    }

    int getSize() override {
        return size;
    }

    bool isFolder() override {
        return false;
    }
    
    ~File() {} 
};