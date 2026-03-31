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
    Team enemyTeam = ctx.getEnemiesOf(user);
    int aliveCounter=0;
    ISkillUser** targetTeam = enemyTeam.getAliveMembers(aliveCounter);
    ISkillUser* target = targetTeam[rand() % aliveCounter];
    target->recieveEffect(DAMAGE,30);
    delete[] targetTeam;
}


