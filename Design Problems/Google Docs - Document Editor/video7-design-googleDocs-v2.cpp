#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
private:
    string text;
public:
    TextElement(string text) {
        this->text = text;
    }

    string render() {
        return text;
    }
};

class ImageElement : public DocumentElement {
private:
    string imagePath;
public:
    ImageElement(string path) {
        this->imagePath = path;
    }

    string render() {
        return "[Image: " + imagePath + "]";
    }
};

class Document {
private:
    vector<DocumentElement*> documentElements;

public:
    void addElements(DocumentElement* docEle) {
        documentElements.push_back(docEle);
    }

    string render() {
        string result;
        for (DocumentElement* docEle : documentElements) 
            result += docEle->render();
        return result;
    }
};

class Persistence {
public:
    virtual void save(string data) = 0;
};

class SaveToFile : public Persistence {
public:
    void save(string data) {
        string fileName = "document1.txt";

        ofstream file;

        file.open(fileName);
        
        file << data << "\n";

        cout << "*****" << "\n";
        cout << "Document has been saved to local device!" << "\n";
        cout << "*****" << "\n";

        file.close();
    }
};

class SaveToDB : public Persistence {
public:
    void save(string data) {
        cout << "Save to DB" << "\n";
    }
};

class DocumentEditor {
private:
    Document* doc;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* doc, Persistence* db) {
        this->doc = doc;
        this->storage = db;
    }

    void save() {
        storage->save(renderedDocument);
    }

    string render() {
        return renderedDocument = doc->render();
    }

    void addText(string data) {
        doc->addElements(new TextElement(data));
    }

    void addImage(string data) {
        doc->addElements(new ImageElement(data));
    }
};

int main() {

    Document* document = new Document();
    Persistence* persistence = new SaveToFile();
    DocumentEditor* editor = new DocumentEditor(document, persistence);

    editor->addText("hey");
    editor->addImage("www.abc.c/abd");

    cout << editor->render();

    editor->save();

    return 0;
}