#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "FileSystemItem.h"

using namespace std;

class Folder : public FileSystemItem {
private:
    string name;
    vector<FileSystemItem*> children;

public:
    Folder(const string& n) {
        this->name = n;
    }

    void add(FileSystemItem* item) {
        children.push_back(item);
    }

    void ls() override {
        for (auto& child : children) {
            cout << child->getName() << "\n";
        }
    }

    void tree() override {
        cout << getName() << "\n";

        for (auto& child : children) {
            child->tree();
        }
    }

    FileSystemItem* cd(const string& dir) override {
        for (auto& child : children) {
            if (child->isFolder() && child->getName() == dir) {
                return child;
            }
        }

        return nullptr;
    }

    string getName() override {
        return name;
    }

    int getSize() override {
        int size = 0;
        
        for (auto& child : children) {
            size += child->getSize();
        }

        return size;
    }

    bool isFolder() override {
        return true;
    }
    
    ~Folder() {
        for (auto child : children) {
            delete child;
        }
    } 
};