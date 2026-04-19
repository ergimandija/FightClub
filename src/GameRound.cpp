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

void GameRound::renderTeam(sf::RenderWindow& window, Team& team, float xPosition, bool mirror) {
    float characterHeight = 200.f;
    float spacing = 20.f;
    float startY = 50.f;

    for (int i = 0; i < team.getMemberCounter(); i++) {
        sf::RectangleShape character({200.f, characterHeight});
        Character* c = dynamic_cast<Character*>(team.getMember(i));
        float y = startY + i * (characterHeight + spacing);
        character.setPosition({xPosition, y});
        character.setTexture(&(c->getTexture()));
        if(mirror){
           character.setScale({-1.f, 1.f});
        }
        window.draw(character);
    }
}

void GameRound::resetAliveCharacters()
{
    Team* teams[2] = { &_teamA, &_teamB };

    for (int t = 0; t < 2; t++)
    {
        Team& team = *teams[t];

        for (int i = 0; i < team.getMemberCounter(); i++)
        {
            Character* c = dynamic_cast<Character*>(team.getMember(i));

            if (c && c->isAlive())
            {

                c->setDefaultTexture();
            }
        }
    }
}
void GameRound::executeTurn(sf::RenderWindow& window)
{
    BattleContext ctx = BattleContext(_teamA, _teamB);

    sf::Texture texture("sand.png");

    texture.setRepeated(true);

    auto handleEvents = [&]()
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    };

    auto render = [&](Team& left, Team& right)
    {
        window.clear();
        handleEvents();

        this->renderField(window, texture);
        this->renderTeam(window, left, 400.f, false);
        this->renderTeam(window, right, 1200.f, true);

        window.display();
    };


    Team* teams[2] = { &_teamA, &_teamB };
    render(_teamA, _teamB);
    for (int t = 0; t < 2; t++)
    {
        Team& current = *teams[t];
        Team& enemy   = *teams[1 - t];

        if (enemy.getAliveMemberCounter() <= 0)
        {
            current.win();
            enemy.lose();
            _isFinished = true;
            return;
        }

        std::cout << "----------------- "
                  << current.getTeamName()
                  << "'s Turn -----------------\n";

        for (int i = 0; i < current.getMemberCounter(); i++)
        {
            if (enemy.getAliveMemberCounter() <= 0)
            {
                current.win();
                enemy.lose();
                _isFinished = true;
                return;
            }

            Character* c = dynamic_cast<Character*>(current.getMember(i));

            if (c && c->isAlive())
            {
                 resetAliveCharacters();
                c->performSkill(ctx);
                render(_teamA, _teamB);
            }


        }
    }
}
