#include <iostream>
#include "Burger.h"

using namespace std;

class MultigrainMcAllo : public Burger {
public:
    void prepare() {
        cout << "Preparing Multigrain McAllo Burger: Potato Pattie + Multigrain Bun" << "\n";
    }
};