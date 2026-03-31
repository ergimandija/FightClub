#ifndef FIREBALL_H
#define FIREBALL_H
#include "ISkill.h"
#include <iostream>

class FireBall: public ISkill
{
    public:
        FireBall();
        virtual ~FireBall();
        void use(ISkillUser* user,BattleContext& ctx) override;

    protected:

    private:
};

#endif // FIREBALL_H
