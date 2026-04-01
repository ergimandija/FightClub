#ifndef BATTLECONTEXT_H
#define BATTLECONTEXT_H
#include "Team.h"
#include "ISkillUser.h"

class BattleContext
{
    public:
        BattleContext();
        BattleContext(Team& teamA, Team& teamB);
        virtual ~BattleContext();
        Team& getAlliesOf(ISkillUser* user);
        Team& getEnemiesOf(ISkillUser* user);
    protected:

    private:
        Team _teamA;
        Team _teamB;
};

#endif // BATTLECONTEXT_H
