#ifndef HEALER_H
#define HEALER_H
#include "CharacterClass.h"
#include "Heal.h"
#include "Revive.h"

class Healer: public CharacterClass
{
    public:
        Healer();
        virtual ~Healer();

    protected:

    private:
};

#endif // HEALER_H
