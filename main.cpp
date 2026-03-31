#include <iostream>
#include "CharacterFactory.h"
#include "Team.h"

using namespace std;

int main() {

    Character* fighter1 = CharacterFactory::createCharacter("Ergi",MAGE,PLAYER);
    Character* fighter2 = CharacterFactory::createCharacter("Enemy",FIGHTER,AI);
    Character* fighter3 = CharacterFactory::createCharacter("Char",FIGHTER,AI);


    Team* team = new Team("teamA");
    team->addCharacter(fighter1);
    team->addCharacter(fighter2);
    team->addCharacter(fighter3);
    int memberCounter;
    Character** teamMembers = team->getAliveMembers(memberCounter);
    for(int i=0;i < memberCounter; i++){
        std::cout << teamMembers[i]->getName() << std::endl;
    }
    delete[] teamMembers;
    return 0;

}
