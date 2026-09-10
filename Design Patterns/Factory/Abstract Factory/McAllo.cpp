#include "Burger.h"

class McAllo : public Burger {
public:
    void prepare() override {
        cout << "Preparing McAllo Burger: Potato Pattie" << endl;
    }
};
