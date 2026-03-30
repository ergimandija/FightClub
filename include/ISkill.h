#ifndef ISKILL_H
#define ISKILL_H
#include "ISkillUser.h"

class ISkill
{
    public:
        ISkill();
        virtual ~ISkill();
        virtual void use(ISkillUser* target) = 0;
    protected:

    private:
};

#endif // ISKILL_H
