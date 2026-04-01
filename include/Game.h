#ifndef GAME_H
#define GAME_H
#include "Team.h"
#include "GameRound.h"
#include "CharacterFactory.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void generateCharacters(Team& t, CharacterType chtype);
        static std::string selectName();
        static ClassType  pickClassType();
        static CharacterType pickTeamMode();
        void start();
        void reset();

    protected:

    private:
        Team _teamA;
        Team _teamB;

};

#endif // GAME_H
