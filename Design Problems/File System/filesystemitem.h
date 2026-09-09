#pragma once

#include <string>

using namespace std;

class FileSystemItem {
private:

public:
    FileSystemItem() {}
    
    virtual void ls() = 0;
    virtual void tree() = 0;
    virtual FileSystemItem* cd(const string& dir) = 0;

    virtual int getSize() = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;

    virtual ~FileSystemItem() {} 
};