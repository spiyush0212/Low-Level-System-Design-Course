#include<iostream>

using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class McAllo : public Burger {
public:
    void prepare() {
        cout << "Preparing McAllo Burger: Potato Pattie" << "\n";
    }
};

class McVeggie : public Burger {
public:
    void prepare() {
        cout << "Preparing McVeggie Burger: Vegetable Pattie" << "\n";
    }
};

class McPaneer : public Burger {
public:
    void prepare() {
        cout << "Preparing McPaneer Burger: Paneer Pattie" << "\n";
    }
};

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

int main() {
    // WITHOUT FACTORY CLASS

    // Burger* burger = new McPaneer();
    // burger->prepare();

    // WITH FACTORY CLASS
    
    string burgerType = "McVeggie"; // User Input
    BurgerFactory* burgerFactory = new BurgerFactory();
    Burger* burger = burgerFactory->createBurger(burgerType);

    burger->prepare();

    delete burger;
    delete burgerFactory;

    return 0;
}