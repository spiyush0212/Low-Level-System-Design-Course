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

class MultigrainMcAllo : public Burger {
public:
    void prepare() {
        cout << "Preparing Multigrain McAllo Burger: Potato Pattie + Multigrain Bun" << "\n";
    }
};

class MultigrainMcVeggie : public Burger {
public:
    void prepare() {
        cout << "Preparing Multigrain McVeggie Burger: Vegetable Pattie + Multigrain Bun" << "\n";
    }
};

class MultigrainMcPaneer : public Burger {
public:
    void prepare() {
        cout << "Preparing MultigrainMcPaneer Burger: Paneer Pattie + Multigrain Bun" << "\n";
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(const string& burgerType) = 0;
    virtual ~BurgerFactory() {}
};

class BurgerKingFactory : public BurgerFactory {
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

int main() {    
    string burgerType = "McVeggie"; // User Input
    BurgerFactory* burgerFactory = new BurgerSinghFactory();
    Burger* burger = burgerFactory->createBurger(burgerType);

    burger->prepare();

    delete burger;
    delete burgerFactory;

    return 0;
}