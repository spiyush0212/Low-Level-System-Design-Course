#pragma once

#include "ISubscriber.h"
#include "Channel.h"
#include <iostream>
#include <string>

using namespace std;

class Subscriber : public ISubscriber {
public:
    Subscriber(const string& name, Channel* channel) : name(name), channel(channel) {}

    virtual ~Subscriber() = default;

    void update() override {
        cout << "Subscriber (" << name << ") received notification. Latest video: " << channel->getLatestVideo() << endl;
    }

private:
    Channel* channel;
    string name;
};
