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
    Team enemyTeam = ctx.getAlliesOf(user);
    int aliveCounter=0;
    ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
    ISkillUser* target = targetTeam[rand() % aliveCounter]
    target->recieveEffect(HEAL,10);
}
