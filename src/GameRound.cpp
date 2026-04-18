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


void GameRound::renderField(sf::RenderWindow& window, sf::Texture& texture){
        sf::RectangleShape field({1600.f, 800.f});
        field.setFillColor(sf::Color(255, 255, 0));
        field.setTextureRect(sf::IntRect({0, 0} , {1600 * 6, 800 * 6}));
        field.setTexture(&texture);
        window.draw(field);
}

void GameRound::renderTeam(sf::RenderWindow& window, Team& team, float xPosition) {
    float characterHeight = 200.f;
    float spacing = 20.f;
    float startY = 50.f;

    for (int i = 0; i < team.getMemberCounter(); i++) {
        sf::RectangleShape character({200.f, characterHeight});
        character.setFillColor(sf::Color(0, 255, 0));

        float y = startY + i * (characterHeight + spacing);
        character.setPosition({xPosition, y});

        window.draw(character);
    }
}

void GameRound::executeTurn(sf::RenderWindow& window){
    BattleContext ctx = BattleContext(_teamA,_teamB);
    sf::Texture texture("sand.png");
    window.clear();
    texture.setRepeated(true);

    this->renderField(window, texture);
    this->renderTeam(window,_teamA,400.f);
    this->renderTeam(window,_teamB,1200.f);
    window.display();
    std::cout << "----------------- " << _teamA.getTeamName() << "'s Turn -----------------" << std::endl;
    for(int i=0;i<_teamA.getMemberCounter();i++){
            if(_teamB.getAliveMemberCounter() > 0){

                Character* c = dynamic_cast<Character*>(_teamA.getMember(i));
                if(c->isAlive()){
                  c->performSkill(ctx);
                }
                window.clear();
                this->renderField(window, texture);
                this->renderTeam(window,_teamA,400.f);
                this->renderTeam(window,_teamB,400.f);
                window.display();
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
            window.clear();
            window.display();
              } else {
                _teamB.win();
                _teamA.lose();
                _isFinished = true;
                return;
            }
    }

}
