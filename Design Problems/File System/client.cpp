#include <iostream>
#include "FileSystemItem.h"
#include "File.h"
#include "Folder.h"

using namespace std;

int main() {

    // ADD FILES
    File* ddlj = new File("Dilwale Dulhania Le Jayenge", 120);
    File* soty = new File("Student Of The Year", 700);
    File* potc = new File("Pirates Of The Carebeian", 878);

    // ADD FOLDERS
    Folder* d = new Folder("Drive-D");
    Folder* movies = new Folder("Movies");
    Folder* engMovies = new Folder("English Movies");
    Folder* hindMovies = new Folder("Hindi Movies");

    // ESTABLISH RELATIONSHIPS
    d->add(movies);
    movies->add(engMovies);
    movies->add(hindMovies);
    engMovies->add(potc);
    hindMovies->add(ddlj);
    hindMovies->add(soty);

    // COMMAND - LS
    cout << "ls from D/ = " << "\n";
    d->ls();
    cout << "ls from D/Movies/ = " << "\n";
    movies->ls();

    // COMMAND - TREE
    cout << "tree from D/ = " << "\n";
    d->tree();

    // COMMAND - SIZE
    cout << "size of D/ = " << "\n";
    cout << d->getSize() << "\n";  

    // COMMAND - CD
    string cdInto = "English Movies";
    FileSystemItem* current = d->cd(cdInto);

    if (current != nullptr) {
        cout << "cd " << cdInto << " successfull" << "\n";
        cout << "Current Directory: " << current->getName() << "\n";
    }
    else {
        cout << "cd " << cdInto << " unsuccessfull" << "\n";
    }

    delete d;

    return 0;
}