#ifndef ISKILL_H
#define ISKILL_H
#include "BattleContext.h"
#include "ISkillUser.h"
class ISkill
{
    public:
        ISkill();
        virtual ~ISkill();
        virtual void use(ISkillUser* user,BattleContext& ctx) = 0;
    protected:

    private:
};

#endif // ISKILL_H
