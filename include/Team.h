#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "Character.h"
class Team
{
    public:
        Team(std::string name);
        virtual ~Team();
        void addCharacter(Character* character);
        Character** getAliveMembers(int& outCount) const;
        int getMemberCounter() const;
        Character* getMember(int index) const;

    protected:

    private:
        std::string _name;
        Character* _members[3];
        int _memberCounter;
};

#endif // TEAM_H
