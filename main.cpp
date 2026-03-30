#include <iostream>
#include "Character.h"
#include "Fighter.h"


using namespace std;

int main() {

    Character fighter1 = Character("fighter1",100, 100, new Fighter());
    Character fighter2 = Character("fighter2", 100,100, new Fighter());

    fighter1.performSkill(&fighter2);
    return 0;

}
