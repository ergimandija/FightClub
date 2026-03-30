#include "AICharacter.h"
#include <time.h>
AICharacter::AICharacter(std::string name, int hp, CharacterClass* chclass): Character(name,hp,chclass)
{

}

AICharacter::~AICharacter()
{
    //dtor
}

void AICharacter::performSkill(ISkillUser* target){
    srand(time(NULL));
    int index =  rand() % 2;
    std::cout << _name << " uses ";
    _class->getSkills()[index]->use(target);

}
