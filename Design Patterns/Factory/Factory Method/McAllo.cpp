#include <iostream>
#include "Burger.h"

using namespace std;

class McAllo : public Burger {
public:
    void prepare() {
        cout << "Preparing McAllo Burger: Potato Pattie" << "\n";
    }
};