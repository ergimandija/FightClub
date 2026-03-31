#include "Amputation.h"
#include <iostream>
#include

Amputation::Amputation()
{
    //ctor
}

Amputation::~Amputation()
{
    //dtor
}


void Amputation::use(ISkillUser* user,BattleContext& ctx){
        std::cout << "Amputation!" << std::endl;
        Team enemyTeam = ctx.getEnemiesOf(user);
        int aliveCounter=0;
        ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
        ISkillUser* target = targetTeam[rand() % aliveCounter];
        target->recieveEffect(DAMAGE,50);
}
