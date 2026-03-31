#ifndef REVIVE_H
#define REVIVE_H
#include "ISkill.h"

class Revive: public ISkill
{
    public:
        Revive();
        virtual ~Revive();
        void use(ISkillUser* user,BattleContext& ctx) override;

    protected:

    private:
};

#endif // REVIVE_H
