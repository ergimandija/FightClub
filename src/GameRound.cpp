#include "GameRound.h"

GameRound::GameRound()
{
    //ctor
}

GameRound::GameRound(Team& teamA, Team& teamB)
{
    _teamA = teamA;
    _teamB = teamB;
    //ctor
}

GameRound::~GameRound()
{
    //dtor
}

bool GameRound::getGameStatus() const{
        return _isFinished;
}
void GameRound::executeTurn(){
    BattleContext ctx = BattleContext(_teamA,_teamB);

    std::cout << "----------------- " << _teamA.getTeamName() << "'s Turn -----------------" << std::endl;
    for(int i=0;i<_teamA.getMemberCounter();i++){
            if(_teamB.getAliveMemberCounter() > 0){
                Character* c = dynamic_cast<Character*>(_teamA.getMember(i));
                if(c->isAlive()){
                    c->performSkill(ctx);
                }
            } else {
                _isFinished = true;
                _teamB.lose();
                _teamA.win();

                return;
            }
    }

    std::cout << "----------------- " << _teamB.getTeamName() << "'s Turn -----------------" << std::endl;
     for(int i=0;i<_teamB.getMemberCounter();i++){
            if(_teamA.getAliveMemberCounter()> 0){
            Character* c = dynamic_cast<Character*>(_teamB.getMember(i));
            if(c->isAlive()){
            c->performSkill(ctx);
            }
              } else {
                _isFinished = true;
                return;
            }
    }

}
