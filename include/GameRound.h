#ifndef GAMEROUND_H
#define GAMEROUND_H
#include "Team.h"
#include "BattleContext.h"
#include "Character.h"
class GameRound
{
    public:
        GameRound();
        GameRound(Team& teamA, Team& teamB);
        virtual ~GameRound();
        void executeTurn();
        bool getGameStatus() const;
    protected:

    private:
        Team _teamA;
        Team _teamB;
        BattleContext _ctx;
        bool _isFinished;
};

#endif // GAMEROUND_H
