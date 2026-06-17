#include <iostream>

using namespace std;

// Interface 
class ITalkable {
public:
    virtual void talk() = 0;
    virtual ~ITalkable() {}
};

class NormalTalk : public ITalkable {
public:
    void talk() override {
        cout << "Talks using actual mouth" << "\n";
    }
};

class NoTalk : public ITalkable {
public:
    void talk() override {
        cout << "Can not talk!!!" << "\n";
    }
};

// Interface
class IFlyable {
public:
    virtual void fly() = 0;
    virtual ~IFlyable() {}
};

class NormalFly : public IFlyable {
public:
    void fly() override {
        cout << "Flies using normal flying method" << "\n";
    }
};

class NoFly : public IFlyable {
public:
    void fly() override {
        cout << "Can not fly!!!" << "\n";
    }
};

class JetFly : public IFlyable {
public:
    void fly() override {
        cout << "Flies using jet powered fly!!!" << "\n";
    }
};

// Parent Class
class Robot {
private:
    ITalkable* t;
    IFlyable* f;

public:
    Robot(ITalkable* talkObject, IFlyable* flyObject) {
        this->t = talkObject;
        this->f = flyObject;
    }

    void talk() {
        t->talk();
    }

    void fly() {
        f->fly();
    }

    virtual void display() = 0;

    virtual ~Robot() {
        delete t;
        delete f;
    }
};

class CompanionRobot : public Robot {
public:
    CompanionRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}

    void display() override {
        cout << "Displaying a companion robot!!!" << "\n";
    }
};

class DummyRobot : public Robot {
public:
    DummyRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}

    void display() override {
        cout << "Displaying a dummy robot!!!" << "\n";
    }
};

class ArmyRobot : public Robot {
public:
    ArmyRobot(ITalkable* t, IFlyable* f) 
        : Robot(t, f) {}
    
    void display() override {
        cout << "Displaying an army robot!!!" << "\n";
    }
};

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