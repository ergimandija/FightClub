#include <iostream>
#include "CharacterFactory.h"

using namespace std;

int main() {

    Character* fighter1 = CharacterFactory::createCharacter("Ergi",MAGE,PLAYER);
    Character* fighter2 = CharacterFactory::createCharacter("Enemy",FIGHTER,AI);

    fighter1->performSkill(fighter2);
    fighter2->performSkill(fighter1);
    return 0;

}
