#pragma once

class ICharacter
{
public:
    virtual ~ICharacter() = default;
    virtual void getAbilities() = 0;
};