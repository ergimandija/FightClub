#ifndef CHARACTER_H
#define CHARACTER_H
#include "CharacterClass.h"
#include "ISkillUser.h"
#include <iostream>
class Character: public ISkillUser
{
    public:
        Character(std::string name, int hp, CharacterClass* chclass);
        virtual ~Character();
        virtual void performSkill(ISkillUser* target);
        void recieveEffect(EffectType type, int amount) override;
        bool isAlive() const;
        std::string getName() const;
    protected:
        CharacterClass* _class;
        std::string _name;
    private:

        int _hp;
        bool _isAlive;

};

#endif // CHARACTER_H
