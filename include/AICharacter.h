#ifndef AICHARACTER_H
#define AICHARACTER_H
#include <iostream>
#include "Character.h"

class AICharacter: public Character
{
    public:
        AICharacter(std::string name, int hp, CharacterClass* chclass);
        virtual ~AICharacter();
        void performSkill(BattleContext& ctx) override;
    protected:

    private:
};

#endif // AICHARACTER_H
