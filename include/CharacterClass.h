#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H
#include "ISkill.h"

class CharacterClass
{
public:
    CharacterClass();
    virtual ~CharacterClass();
    ISkill* const* getSkills() const;
    std::string getTexturePath() const;

protected:
    ISkill* skills[2];
    std::string _texturePath;
private:


};

#endif // CHARACTERCLASS_H
