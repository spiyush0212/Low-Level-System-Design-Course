#include <string>
#include "Burger.h"
#include "McAllo.cpp"
#include "McVeggie.cpp"
#include "McPaneer.cpp"

using namespace std;

class BurgerFactory {
public:
    Burger* createBurger(const string& burgerType) {
        if (burgerType == "McAllo")
            return new McAllo();
        if (burgerType == "McVeggie")
            return new McVeggie();
        if (burgerType == "McPaneer")
            return new McPaneer();
        else
            return nullptr;
    }
};