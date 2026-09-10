#include "Burger.h"

class MultigrainMcPaneer : public Burger {
public:
    void prepare() override {
        cout << "Preparing MultigrainMcPaneer Burger: Paneer Pattie + Multigrain Bun" << endl;
    }
};
