#pragma once

#include <string>
#include "Document.h"
#include "ImageElement.h"
#include "Persistence.h"
#include "TextElement.h"
using namespace std;

class DocumentEditor {
private:
    Document* document_;
    Persistence* storage_;
    string renderedDocument_;

public:
    DocumentEditor(Document* document, Persistence* storage)
        : document_(document), storage_(storage), renderedDocument_() {}

    ~DocumentEditor() {
        delete document_;
        delete storage_;
    }

    string render() {
        renderedDocument_ = document_->render();
        return renderedDocument_;
    }

    void save() {
        if (storage_ != nullptr) {
            storage_->save(renderedDocument_);
        }
    }

    void addText(const string& text) {
        document_->addElement(new TextElement(text));
    }

    void addImage(const string& imagePath) {
        document_->addElement(new ImageElement(imagePath));
    }
};
