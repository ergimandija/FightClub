#include "FireBall.h"

FireBall::FireBall()
{
    //ctor
}

FireBall::~FireBall()
{
    //dtor
}

void FireBall::use(ISkillUser* target){
    std::cout << "Fireball!" <<  std::endl;
    target->recieveEffect(DAMAGE,30);

}


