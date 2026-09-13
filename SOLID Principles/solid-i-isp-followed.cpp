#include <iostream>

using namespace std;

class TwoDShape {
public:
    virtual double area() const = 0;
};

class ThreeDShape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

class Square : public TwoDShape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    
    double area() const override {
        return side * side;
    }
};

class Rectangle : public TwoDShape {
private:
    double length;
    double width;   
public:
    Rectangle(double l, double w) : length(l), width(w) {}      
    
    double area() const override {
        return length * width;
    }
};

class Cube : public ThreeDShape {
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

    cout << "Area of square: " << square.area() << endl;
    cout << "Area of rectangle: " << rectangle.area() << endl;
    cout << "Area of cube: " << cube.area() << endl;
    cout << "Volume of cube: " << cube.volume() << endl;

    return 0;
}