#include <iostream>
#include "Character.h"
#include "AICharacter.h"
#include "Fighter.h"
#include "Mage.h"
#include  "Healer.h"

using namespace std;

int main() {

    Character* fighter1 = new Character("fighter1",100, new Fighter());
    Character* fighter2 = new AICharacter("fighter2", 100, new Mage());

    fighter1->performSkill(fighter2);
    fighter2->performSkill(fighter1);
    return 0;

}
