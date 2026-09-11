#pragma once

#include <string>
#include "DocumentElement.h"
using namespace std;

class TextElement : public DocumentElement {
private:
    string text_;

public:
    explicit TextElement(const string& text) : text_(text) {}

    string render() const override {
        return text_;
    }
};
