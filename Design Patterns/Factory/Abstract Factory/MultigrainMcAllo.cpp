#include "Burger.h"

class MultigrainMcAllo : public Burger {
public:
    void prepare() override {
        cout << "Preparing Multigrain McAllo Burger: Potato Pattie + Multigrain Bun" << endl;
    }
};
