#include <iostream>
#include "Burger.h"

using namespace std;

class McVeggie : public Burger {
public:
    void prepare() {
        cout << "Preparing McVeggie Burger: Vegetable Pattie" << "\n";
    }
};