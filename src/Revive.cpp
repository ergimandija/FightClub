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


void Revive::use(ISkillUser* user,BattleContext& ctx) {
    std::cout << "Revive!" << std::endl;
    Team enemyTeam = ctx.getAlliesOf(user);
    int aliveCounter=0;
    ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
    ISkillUser* target = targetTeam[rand() % aliveCounter];
    target->recieveEffect(REVIVE,20);
    delete[] targetTeam;
}
