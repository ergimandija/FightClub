#include "CharacterClass.h"

CharacterClass::CharacterClass()
{
    //ctor
}

CharacterClass::~CharacterClass()
{
    for (int i = 0; i < 2; i++) {
        delete skills[i];
    }
}


ISkill** CharacterClass::getSkills(){
    return skills;
}
