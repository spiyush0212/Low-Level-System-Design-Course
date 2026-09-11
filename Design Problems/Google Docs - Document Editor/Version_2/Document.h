#pragma once

#include <string>
#include <vector>
#include "DocumentElement.h"

using namespace std;

class Document {
private:
    vector<DocumentElement*> elements_;

public:
    void addElement(DocumentElement* element) {
        elements_.push_back(element);
    }

    string render() const {
        string result;
        for (const DocumentElement* element : elements_) {
            result += element->render();
        }
        return result;
    }

    ~Document() {
        for (DocumentElement* element : elements_) {
            delete element;
        }
    }
};
