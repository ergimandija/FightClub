#include "Revive.h"
#include <iostream>
Revive::Revive()
{
    //ctor
}

Revive::~Revive()
{
    //dtor
}


void Revive::use(ISkillUser* target) {
    std::cout << "Revive!" << std::endl;
    target->recieveEffect(REVIVE,20);

}
