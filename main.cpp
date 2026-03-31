#include <iostream>
#include "CharacterFactory.h"
#include "Team.h"
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
    Character* fighter1 = CharacterFactory::createCharacter("Ergi",MAGE,PLAYER);
    Character* fighter2 = CharacterFactory::createCharacter("Enemy",FIGHTER,AI);
    Character* fighter3 = CharacterFactory::createCharacter("Char",FIGHTER,AI);


    Team* team = new Team("teamA");
    team->addCharacter(fighter1);
    team->addCharacter(fighter2);
    team->addCharacter(fighter3);
    int memberCounter;
    ISkillUser** teamMembers = team->getAliveMembers(memberCounter);

    delete[] teamMembers;
    return 0;

}
