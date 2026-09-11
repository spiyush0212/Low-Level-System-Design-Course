#pragma once

#include "ICharacter.h"

class IDecorator : public ICharacter {
public:
    IDecorator(ICharacter* ch) : character(ch) {}
    virtual ~IDecorator() = default;
    virtual void getAbilities() = 0;

protected:
    ICharacter* character;
};