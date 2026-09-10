#include <iostream>
#include "Burger.h"

using namespace std;

class MultigrainMcPaneer : public Burger {
public:
    void prepare() {
        cout << "Preparing MultigrainMcPaneer Burger: Paneer Pattie + Multigrain Bun" << "\n";
    }
};