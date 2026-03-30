#include "Lightning.h"
#include <iostream>

Lightning::Lightning()
{
    //ctor
}

Lightning::~Lightning()
{
    //dtor
}


void Lightning::use(ISkillUser* target){
    std::cout<< "Lighting!" << std::endl;
    target->recieveEffect(DAMAGE,50);
}
