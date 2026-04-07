#include "GameRound.h"



GameRound::GameRound(Team& teamA, Team& teamB)
    : _teamA(teamA), _teamB(teamB)
{
        _isFinished=false;

}

GameRound::~GameRound()
{
    //dtor
}

bool GameRound::getGameStatus() const{
        return _isFinished;
}


void GameRound::setGameStatus(bool val) {
        _isFinished = val;
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
                _teamB.lose();
                _teamA.win();
                _isFinished = true;
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
                _teamB.win();
                _teamA.lose();
                _isFinished = true;
                return;
            }
    }

}
