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
    Team enemyTeam = ctx.getEnemiesOf(user);
    int aliveCounter=0;
    ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
    ISkillUser* target = targetTeam[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,10);

}
