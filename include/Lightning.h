#ifndef LIGHTNING_H
#define LIGHTNING_H
#include "ISkill.h"

class Lightning: public ISkill
{
    public:
        Lightning();
        virtual ~Lightning();
        void use(ISkillUser* target) override;
    protected:

    private:
};

#endif // LIGHTNING_H
