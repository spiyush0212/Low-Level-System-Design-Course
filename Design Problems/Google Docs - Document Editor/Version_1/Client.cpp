#include <iostream>
#include "DocumentEditor.h"

using namespace std;

int main() {
    DocumentEditor* myFile = new DocumentEditor("microsoft.txt");

    myFile->addText("Microsoft is a software MNC");
    myFile->addText("The icon of microsoft is");
    myFile->addImage("https://www.microsoft.com/icon.jpg");
    
    cout << myFile->render();
    myFile->save();

    return 0;
}
