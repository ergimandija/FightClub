#ifndef AMPUTATION_H
#define AMPUTATION_H
#include "ISkill.h"

class Amputation: public ISkill
{
    public:
        Amputation();
        virtual ~Amputation();
        void use(ISkillUser* user,BattleContext& ctx) override;
    protected:

    private:
};

#endif // AMPUTATION_H
