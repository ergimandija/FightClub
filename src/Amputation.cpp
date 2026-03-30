#include "Amputation.h"
#include <iostream>

Amputation::Amputation()
{
    //ctor
}

Amputation::~Amputation()
{
    //dtor
}


void Amputation::use(ISkillUser* target){
        std::cout << "Amputation!" << std::endl;
        target->recieveEffect(DAMAGE,50);
}
