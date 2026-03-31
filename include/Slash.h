#ifndef SLASH_H
#define SLASH_H
#include "ISkill.h"

class Slash:public ISkill
{
    public:
        Slash();
        virtual ~Slash();
        void use(ISkillUser* user,BattleContext& ctx) override;
    protected:

    private:
};

#endif // SLASH_H
