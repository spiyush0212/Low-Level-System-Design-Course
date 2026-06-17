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

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {}
};

class PlainGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout << "Preparing Plain Garlic Bread: No Cheese" << "\n";
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout << "Preparing Cheese Garlic Bread: With Cheese";
    }
};

class MealFactory {
public:
    virtual Burger* createBurger(const string& burgerType) = 0;
    virtual GarlicBread* createGarlicBread(const string& garlicBreadType) = 0;
    virtual ~MealFactory() {}
};

class BurgerKingMealFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(const string& garlicBreadType) {
        if (garlicBreadType == "Plain")
            return new PlainGarlicBread();
        if (garlicBreadType == "Cheese")
            return new CheeseGarlicBread();
        else
            return nullptr;
    }
};

class BurgerSinghMealFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(const string& garlicBreadType) {
        if (garlicBreadType == "Plain")
            return new PlainGarlicBread();
        if (garlicBreadType == "Cheese")
            return new CheeseGarlicBread();
        else
            return nullptr;
    }
};

int main() {    
    string burgerType = "McVeggie"; // User Input
    string garlicBreadType = "Plain"; // User Input

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