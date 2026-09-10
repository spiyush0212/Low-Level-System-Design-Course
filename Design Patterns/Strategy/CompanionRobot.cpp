#include <iostream>
#include "ITalkable.h"
#include "IFlyable.h"
#include "Robot.h"

using namespace std;

class CompanionRobot : public Robot {
public:
    CompanionRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}

    void display() override {
        cout << "Displaying a companion robot!!!" << "\n";
    }
};
