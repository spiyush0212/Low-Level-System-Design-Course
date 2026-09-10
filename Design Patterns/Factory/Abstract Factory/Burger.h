#pragma once

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};
