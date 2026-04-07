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
    Team targetTeam = ctx.getAlliesOf(user);
    ISkillUser* const* targets = targetTeam.getMembers();
    int counter = targetTeam.getMemberCounter();
    ISkillUser* target = targets[rand() % counter];
    target->recieveEffect(REVIVE,20);
}
