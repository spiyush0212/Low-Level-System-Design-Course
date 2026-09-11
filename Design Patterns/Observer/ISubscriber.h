#pragma once

class ISubscriber {
public:
    ISubscriber() = default;
    virtual ~ISubscriber() = default;
    virtual void update() = 0;
};
