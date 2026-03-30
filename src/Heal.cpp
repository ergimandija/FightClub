#include "Heal.h"
#include <iostream>

Heal::Heal()
{
    //ctor
}

Heal::~Heal()
{
    //dtor
}

void Heal::use(ISkillUser* target){
    std::cout << "Heal!" << std::endl;
    target->recieveEffect(HEAL,10);
}
