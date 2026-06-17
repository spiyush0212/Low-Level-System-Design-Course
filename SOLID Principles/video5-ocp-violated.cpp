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

class SaveToDatabase {
private:
    ShoppingCart* cart;

public:
    SaveToDatabase(ShoppingCart* cart) : cart(cart) {}

    void storeToDatabase() {
        // Code to store cart information in a database
        cout << "Storing cart information to the database..." << endl;
    }

    void storeToMongoDB() {
        // Code to store cart information in MongoDB
        cout << "Storing cart information to MongoDB..." << endl;
    }

    void storeToSQLDatabase() {
        // Code to store cart information in SQL database
        cout << "Storing cart information to SQL database..." << endl;
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
    databaseSaver->storeToDatabase();
    databaseSaver->storeToMongoDB();
    databaseSaver->storeToSQLDatabase();

    delete product1;
    delete product2;
    delete cart;

    return 0;
}