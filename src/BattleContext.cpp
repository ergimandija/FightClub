#include "BattleContext.h"

BattleContext::BattleContext(Team& teamA, Team& teamB)
{
    _teamA = teamA;
    _teamB = teamB;
}

BattleContext::~BattleContext()
{
    //dtor
}


Team& BattleContext::getAlliesOf(ISkillUser* user) {
        if(!user){
            throw std::invalid_argument("User pointer is null");
        }
        for(int i=0;i<_teamA.getMemberCounter();i++){
            if(user==_teamA.getMember(i)){
                return _teamA;
            }
        }
        return _teamB;
}

Team& BattleContext::getEnemiesOf(ISkillUser* user) {
    if(!user){
            throw std::invalid_argument("User pointer is null");
    }
    for(int i=0;i<_teamA.getMemberCounter();i++){
        if(user==_teamA.getMember(i)){
            return _teamB;
        }
    }
    return _teamA;
}
