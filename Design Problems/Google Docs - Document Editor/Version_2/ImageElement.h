#pragma once

#include <string>
#include "DocumentElement.h"
using namespace std;

class ImageElement : public DocumentElement {
private:
    string imagePath_;

public:
    explicit ImageElement(const string& imagePath) : imagePath_(imagePath) {}

    string render() const override {
        return "[Image: " + imagePath_ + "]";
    }
};
