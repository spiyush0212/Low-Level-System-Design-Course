#include "Burger.h"

class McPaneer : public Burger {
public:
    void prepare() override {
        cout << "Preparing McPaneer Burger: Paneer Pattie" << endl;
    }
};
