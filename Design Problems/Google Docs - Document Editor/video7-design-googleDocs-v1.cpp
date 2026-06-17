#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentEditor {
private:
    vector<string> elements;
    string fileName;
    string document;
    bool renderAgain = false;

public:
    DocumentEditor(string fileName = "doc.txt") {
        this->fileName = fileName; 
    }

    void addText(const string& text) {
        elements.push_back(text);
        renderAgain = true;
    }

    void addImage(const string& path) {
        elements.push_back(path);
        renderAgain = true;
    }

    string render() {
        if (renderAgain == true) {
            string result;
            for (string element : elements) {
                if (element.size() > 4 && element.substr(element.size() - 4) == ".jpg") {
                    result += "Img Path = " + element + "\n";
                }
                else {
                    result += element + "\n";
                }
            }
            renderAgain = false;
            document = result;
        }

        return document;
    }

    void save() {
        ofstream file;
        file.open(this->fileName);
        for (string element : elements)
            file << element << "\n";
        cout << "*****" << "\n";
        cout << "Document has been saved to local device!" << "\n";
        cout << "*****" << "\n";
        file.close();
    }
};

int main() {
    DocumentEditor* myFile = new DocumentEditor("microsoft.txt");
    myFile->addText("Microsoft is a software MNC");
    myFile->addText("The icon of microsoft is");
    myFile->addImage("https://www.microsoft.com/icon.jpg");
    cout << myFile->render();
    myFile->save();

    return 0;
}
