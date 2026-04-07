#include "Amputation.h"
#include <iostream>

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
        Team targetTeam = ctx.getEnemiesOf(user);
        ISkillUser** targets = targetTeam.getAliveMembers();
        int aliveCounter= targetTeam.getAliveMemberCounter();
        ISkillUser* target = targets[rand() % aliveCounter];
        target->recieveEffect(DAMAGE,50);
        delete[] targets;
}
