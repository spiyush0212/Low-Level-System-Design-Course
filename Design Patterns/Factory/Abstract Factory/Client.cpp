#include <iostream>
#include "BurgerKingMealFactory.h"
#include "BurgerSinghMealFactory.h"

using namespace std;

int main() {
    string burgerType = "McVeggie";
    string garlicBreadType = "Plain";

    MealFactory* mealFactory = new BurgerSinghMealFactory();

    Burger* burger = mealFactory->createBurger(burgerType);
    burger->prepare();

    GarlicBread* garlicBread = mealFactory->createGarlicBread(garlicBreadType);
    garlicBread->prepare();

    delete garlicBread;
    delete burger;
    delete mealFactory;

    return 0;
}
