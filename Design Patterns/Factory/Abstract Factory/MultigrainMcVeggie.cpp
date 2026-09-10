#include "Burger.h"

class MultigrainMcVeggie : public Burger {
public:
    void prepare() override {
        cout << "Preparing Multigrain McVeggie Burger: Vegetable Pattie + Multigrain Bun" << endl;
    }
};
