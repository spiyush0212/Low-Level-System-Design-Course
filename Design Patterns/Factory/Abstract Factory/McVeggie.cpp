#include "Burger.h"

class McVeggie : public Burger {
public:
    void prepare() override {
        cout << "Preparing McVeggie Burger: Vegetable Pattie" << endl;
    }
};
