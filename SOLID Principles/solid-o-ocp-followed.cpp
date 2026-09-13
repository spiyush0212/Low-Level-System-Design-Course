#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {}
};

class ShoppingCart {
public:
    vector<Product*> products;

    void addProduct(Product* product) {
        products.push_back(product);
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& product : products) {
            total += product->price;
        }
        return total;
    }
};

class PrintShoppingCart {
private:
    ShoppingCart* cart;

public:
    PrintShoppingCart(ShoppingCart* cart) : cart(cart) {}

    void printInvoice() {
        cout << "Shopping Cart:" << endl;
        for (const auto& product : cart->getProducts()) {
            cout << "- " << product->name << ": $" << product->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

// Abstract Class
class Persistence {
protected:
    ShoppingCart* cart;

public:
    Persistence(ShoppingCart* cart) : cart(cart) {}

    virtual void save() = 0;

    virtual ~Persistence() {}
};

// Implements the abstract class (Interface)
class SaveToDatabase : public Persistence {
public:
    SaveToDatabase(ShoppingCart* cart) : Persistence(cart) {}

    void save() override {
        cout << "Storing cart information to the database..." << endl;
    }
};

class SaveToMongoDB : public Persistence {
public:    
    SaveToMongoDB(ShoppingCart* cart) : Persistence(cart) {}

    void save() override {
        cout << "Storing cart information to MongoDB..." << endl;
    }
};

class SaveToFile : public Persistence {
public:
    SaveToFile(ShoppingCart* cart) : Persistence(cart) {}

    void save() override {
        cout << "Storing cart information to a file..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    
    Product* product1 = new Product("Laptop", 999.99);
    Product* product2 = new Product("Smartphone", 499.99);

    cart->addProduct(product1);
    cart->addProduct(product2);

    PrintShoppingCart* printer = new PrintShoppingCart(cart);
    printer->printInvoice();

    SaveToDatabase* databaseSaver = new SaveToDatabase(cart);
    databaseSaver->save();

    SaveToMongoDB* mongoSaver = new SaveToMongoDB(cart);
    mongoSaver->save();

    SaveToFile* fileSaver = new SaveToFile(cart);
    fileSaver->save();

    delete databaseSaver;
    delete printer;
    delete product2;
    delete product1;
    delete cart;

    return 0;
}