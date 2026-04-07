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

void Heal::use(ISkillUser* user,BattleContext& ctx){
    std::cout << "Heal!" << std::endl;
    Team targetTeam = ctx.getAlliesOf(user);
    ISkillUser** targets = targetTeam.getAliveMembers();
    int aliveCounter= targetTeam.getAliveMemberCounter();
    ISkillUser* target = targets[rand() % aliveCounter];
    target->recieveEffect(HEAL,10);
    delete[] targets;
}
