#include <iostream>
#include "ITalkable.h"
#include "IFlyable.h"
#include "Robot.h"
#include "CompanionRobot.cpp"
#include "DummyRobot.cpp"
#include "ArmyRobot.cpp"
#include "NormalTalk.cpp"
#include "NoTalk.cpp"
#include "NormalFly.cpp"
#include "NoFly.cpp"
#include "JetFly.cpp"

using namespace std;

int main() {

    Robot* companionRobot = new CompanionRobot(
        new NormalTalk(), 
        new NormalFly()
    );

    Robot* dummyRobot = new DummyRobot(new NoTalk(), new NoFly());
    Robot* armyRobot = new ArmyRobot(new NormalTalk(), new JetFly());

    companionRobot->display();
    companionRobot->talk();
    companionRobot->fly();

    cout << "\n";

    dummyRobot->display();
    dummyRobot->talk();
    dummyRobot->fly();

    cout << "\n";


    armyRobot->display();
    armyRobot->talk();
    armyRobot->fly();

    delete armyRobot;
    delete dummyRobot;
    delete companionRobot;

    return 0;
}