#include <iostream>
#include "Burger.h"

using namespace std;

class MultigrainMcVeggie : public Burger {
public:
    void prepare() {
        cout << "Preparing Multigrain McVeggie Burger: Vegetable Pattie + Multigrain Bun" << "\n";
    }
};