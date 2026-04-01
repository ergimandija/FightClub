#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "ISkillUser.h"
class Team
{
    public:
        Team(std::string name);
        Team();
        virtual ~Team();
        void addCharacter(ISkillUser* character);
        ISkillUser** getAliveMembers(int& outCount) const;
        int getMemberCounter() const;
        ISkillUser* getMember(int index) const;
        int getAliveMemberCounter();
        std::string getTeamName() const;
        void resetTeam();
        void win();
        void lose();
        void showStats() const;
    protected:

    private:
        std::string _name;
        ISkillUser* _members[3];
        int _memberCounter;
        int _wins;
        int _losses;
};

#endif // TEAM_H
