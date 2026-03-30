#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H
#include "AICharacter.h"
#include "Fighter.h"
#include "Mage.h"
#include  "Healer.h"
#include <iostream>

enum CharacterType {
    AI,
    PLAYER
};

enum ClassType {
    FIGHTER,
    MAGE,
    HEALER
};
class CharacterFactory
{
    public:
        CharacterFactory();
        virtual ~CharacterFactory();
        static Character* createCharacter(std::string name, ClassType classType, CharacterType chType);
    protected:

    private:
};

#endif // CHARACTERFACTORY_H
