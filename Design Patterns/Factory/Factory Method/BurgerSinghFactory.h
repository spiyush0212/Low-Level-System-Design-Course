#include "Burger.h"
#include "BurgerFactory.h"
#include "MultigrainMcAllo.cpp"
#include "MultigrainMcVeggie.cpp"
#include "MultigrainMcPaneer.cpp"

using namespace std;

class BurgerSinghFactory : public BurgerFactory {
public:
    Burger* createBurger(const string& burgerType) {
        if (burgerType == "McAllo")
            return new MultigrainMcAllo();
        if (burgerType == "McVeggie")
            return new MultigrainMcVeggie();
        if (burgerType == "McPaneer")
            return new MultigrainMcPaneer();
        else
            return nullptr;
    }
};