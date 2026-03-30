#ifndef CHARACTER_H
#define CHARACTER_H
#include "CharacterClass.h"
#include "ISkillUser.h"
#include <iostream>
class Character: public ISkillUser
{
    public:
        Character(std::string name, int hp, int xp, CharacterClass* chclass);
        virtual ~Character();
        void performSkill(ISkillUser* user);
        void recieveEffect(EffectType type, int amount) override;
    protected:

    private:
        CharacterClass* _class;
        int _hp;
        int _xp;
        std::string _name;
};

#endif // CHARACTER_H
