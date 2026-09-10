#include <iostream>
#include "BurgerFactory.cpp"
#include "Burger.h"

using namespace std;

int main() {
    // WITHOUT FACTORY CLASS

    // Burger* burger = new McPaneer();
    // burger->prepare();

    // WITH FACTORY CLASS
    
    string burgerType = "McVeggie"; // User Input
    BurgerFactory* burgerFactory = new BurgerFactory(); // Create a burger factory object
    Burger* burger = burgerFactory->createBurger(burgerType); // Create a burger object using the factory

    burger->prepare();

    delete burger;
    delete burgerFactory;

    return 0;
}