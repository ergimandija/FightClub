#ifndef HEAL_H
#define HEAL_H
#include "ISkill.h"

class Heal: public ISkill
{
    public:
        Heal();
        virtual ~Heal();
        void use(ISkillUser* target) override;
    protected:

    private:
};

#endif // HEAL_H
