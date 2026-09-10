#include <iostream>
#include "ITalkable.h"
#include "IFlyable.h"
#include "Robot.h"

using namespace std;

class ArmyRobot : public Robot {
public:
    ArmyRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}
    
    void display() override {
        cout << "Displaying an army robot!!!" << "\n";
    }
};
