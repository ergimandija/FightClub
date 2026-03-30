#include "Slash.h"
#include <iostream>

Slash::Slash()
{
    //ctor
}

Slash::~Slash()
{
    //dtor
}
void Slash::use(ISkillUser* target){
    std::cout << "Slash!" <<  std::endl;
    target->recieveEffect(DAMAGE,10);

}
