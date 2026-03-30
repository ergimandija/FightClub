#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H
#include "ISkill.h"

class CharacterClass
{
public:
    CharacterClass();
    virtual ~CharacterClass();
    ISkill** getSkills();


protected:
    ISkill* skills[2];
private:


};

#endif // CHARACTERCLASS_H
