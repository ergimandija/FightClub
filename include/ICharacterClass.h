#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H
#include "ISkill.h"

class CharacterClass
{
public:
    ICharacterClass();
    virtual ~ICharacterClass();
    ISkill* getSkill(int index);

protected:
    ISkill* skills[2];
private:


};

#endif // CHARACTERCLASS_H
