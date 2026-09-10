#pragma once

#include "ITalkable.h"
#include "IFlyable.h"

using namespace std;

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