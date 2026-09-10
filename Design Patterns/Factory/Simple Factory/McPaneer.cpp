#include <iostream>
#include "Burger.h"

using namespace std;

class McPaneer : public Burger {
public:
    void prepare() {
        cout << "Preparing McPaneer Burger: Paneer Pattie" << "\n";
    }
};