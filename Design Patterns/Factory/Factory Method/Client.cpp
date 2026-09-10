#include <iostream>
#include "BurgerFactory.h"
#include "BurgerSinghFactory.h"
#include "Burger.h"

using namespace std;

int main() {    
    string burgerType = "McVeggie"; // User Input for burger type
    BurgerFactory* burgerFactory = new BurgerSinghFactory(); // Create a burger factory object for Burger Singh
    Burger* burger = burgerFactory->createBurger(burgerType); // Create a burger object using the factory

    burger->prepare();

    delete burger;
    delete burgerFactory;

    return 0;
}