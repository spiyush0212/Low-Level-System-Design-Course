#pragma once

#include "ISubscriber.h"

class IChannel {
public:
    IChannel() = default;
    virtual ~IChannel() = default;
    virtual void notify() = 0;
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
};