#include "FireBall.h"

FireBall::FireBall()
{
    //ctor
}

FireBall::~FireBall()
{
    //dtor
}

void FireBall::use(ISkillUser* user,BattleContext& ctx){
    std::cout << "Fireball!" <<  std::endl;
    Team targetTeam = ctx.getEnemiesOf(user);
    ISkillUser** targets = targetTeam.getAliveMembers();
    int aliveCounter= targetTeam.getAliveMemberCounter();
    ISkillUser* target = targets[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,30);
    delete[] targets;
}


