#ifndef GAMEROUND_H
#define GAMEROUND_H
#include "Team.h"
#include "BattleContext.h"
#include "Character.h"
#include <SFML/Graphics.hpp>

class GameRound
{
    public:
        GameRound();
        GameRound(Team& teamA, Team& teamB);
        virtual ~GameRound();
        void renderTeam(sf::RenderWindow& window, Team& team, float xPosition);
        void renderField(sf::RenderWindow& window,sf::Texture& texture);
        void executeTurn(sf::RenderWindow& window);
        bool getGameStatus() const;
        void setGameStatus(bool val);

    protected:

    private:
        Team& _teamA;
        Team& _teamB;
        BattleContext _ctx;
        bool _isFinished;
};

#endif // GAMEROUND_H
