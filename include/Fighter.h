#ifndef FIGHTER_H
#define FIGHTER_H
#include "CharacterClass.h"
#include "ISkill.h"
#include "Amputation.h"
#include "Slash.h"

class Fighter: public CharacterClass
{
    public:
        Fighter();
        virtual ~Fighter();

    protected:

    private:

};

#endif // FIGHTER_H
