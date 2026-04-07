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
void Slash::use(ISkillUser* user,BattleContext& ctx){
    std::cout << "Slash!" <<  std::endl;
    Team targetTeam = ctx.getEnemiesOf(user);
    ISkillUser** targets = targetTeam.getAliveMembers();
    int aliveCounter= targetTeam.getAliveMemberCounter();
    ISkillUser* target = targets[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,10);
    delete[] targets;
}
