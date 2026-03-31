#include "AICharacter.h"
AICharacter::AICharacter(std::string name, int hp, CharacterClass* chclass): Character(name,hp,chclass)
{

}

AICharacter::~AICharacter()
{
    //dtor
}

void AICharacter::performSkill(BattleContext& ctx){

    int index =  rand() % 2;

    std::cout << _name << " uses ";
    _class->getSkills()[index]->use(this,ctx);

}
