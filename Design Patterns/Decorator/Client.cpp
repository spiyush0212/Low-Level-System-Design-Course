#include <iostream>
#include <string>
#include "ICharacter.h"
#include "Mario.h"
#include "IDecorator.h"
#include "RunDecorator.h"
#include "SwimDecorator.h"

using namespace std;

int main() {
    ICharacter* character = new RunDecorator(new SwimDecorator(new Mario("mario")));
    character->getAbilities();

    delete character;

    return 0;
}