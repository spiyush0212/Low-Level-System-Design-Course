#include <iostream>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    
    double area() const override {
        return side * side;
    }
    
    double volume() const override {
        throw logic_error("Volume is not applicable for a square.");
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}      
    
    double area() const override {
        return length * width;
    }
    
    double volume() const override {
        throw logic_error("Volume is not applicable for a rectangle.");
    }
};

class Cube : public Shape {
private:
    double side;
public:
    Cube(double s) : side(s) {}
    
    double area() const override {
        return 6 * side * side;
    }
    
    double volume() const override {
        return side * side * side;
    }
};

int main() {
    Square square(5);
    Rectangle rectangle(4, 6);
    Cube cube(3);

    cout << "Square Area: " << square.area() << endl;
    cout << "Rectangle Area: " << rectangle.area() << endl;
    cout << "Cube Area: " << cube.area() << endl;

    try {
        cout << "Square Volume: " << square.volume() << endl;
    } catch (const logic_error& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "Rectangle Volume: " << rectangle.volume() << endl;
    } catch (const logic_error& e) {
        cout << e.what() << endl;
    }

    cout << "Cube Volume: " << cube.volume() << endl;

    return 0;
}