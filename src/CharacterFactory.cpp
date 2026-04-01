#include "CharacterFactory.h"

CharacterFactory::CharacterFactory()
{
    //ctor
}

CharacterFactory::~CharacterFactory()
{
    //dtor
}

Character* CharacterFactory::createCharacter(std::string name, ClassType classType, CharacterType chType){
    CharacterClass* chclass;
    switch(classType) {
    case HEALER:
        chclass = new Healer();
        break;
    case FIGHTER:
        chclass = new Fighter();
        break;
    case MAGE:
        chclass= new Mage();
        break;
    case CUSTOM:
        chclass = new Custom();
        break;
    }

    Character* newCharacter;
    switch(chType) {
    case AI:
        newCharacter = new AICharacter(name,100,chclass);
        break;
    case PLAYER:
        newCharacter = new Character(name,100,chclass);
        break;
    default:
        newCharacter = new Character(name,100,chclass);
        break;
    }
    return newCharacter;


}
