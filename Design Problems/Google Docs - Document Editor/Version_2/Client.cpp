#include <iostream>
#include "Document.h"
#include "DocumentEditor.h"
#include "SaveToFile.h"

int main() {
    Document* document = new Document();
    Persistence* persistence = new SaveToFile("document1.txt");
    DocumentEditor editor(document, persistence);

    editor.addText("hey");
    editor.addImage("www.abc.c/abd");

    std::cout << editor.render();
    editor.save();

    return 0;
}
