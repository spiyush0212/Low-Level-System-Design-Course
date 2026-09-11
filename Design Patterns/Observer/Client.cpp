#include <iostream>
#include "IChannel.h"
#include "Channel.h"
#include "ISubscriber.h"
#include "Subscriber.h"

using namespace std;

int main() {
    Channel* channel = new Channel("CoderArmy");

    ISubscriber* subscriberAlice = new Subscriber("Alice", channel);
    ISubscriber* subscriberBob = new Subscriber("Bob", channel);

    channel->subscribe(subscriberAlice);
    channel->subscribe(subscriberBob);

    channel->publishVideo("Video 1");
    channel->publishVideo("Video 2");

    channel->unsubscribe(subscriberAlice);

    channel->publishVideo("Video 3");

    delete channel;
    delete subscriberAlice;
    delete subscriberBob;

    return 0;
}