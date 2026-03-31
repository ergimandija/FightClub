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
    Team enemyTeam = ctx.getEnemiesOf(user);
    int aliveCounter=0;
    ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
    ISkillUser* target = targetTeam[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,50);
}
