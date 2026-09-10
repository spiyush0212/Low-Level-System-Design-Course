#include <iostream>
#include "ITalkable.h"
#include "IFlyable.h"
#include "Robot.h"

using namespace std;

class DummyRobot : public Robot {
public:
    DummyRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}

    void display() override {
        cout << "Displaying a dummy robot!!!" << "\n";
    }
};
