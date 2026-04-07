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


void Lightning::use(ISkillUser* user,BattleContext& ctx){
    std::cout<< "Lighting!" << std::endl;
    Team targetTeam = ctx.getEnemiesOf(user);
    ISkillUser** targets = targetTeam.getAliveMembers();
    int aliveCounter= targetTeam.getAliveMemberCounter();
    ISkillUser* target = targets[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,50);
    delete[] targets;
}
