#include "Character.h"

Character::Character(std::string name, int hp, int xp, CharacterClass* chclass)
{
    _name = name;
    _hp = hp;
    _xp = xp;
    _class = chclass;
}

Character::~Character()
{
    //dtor
}

void Character::recieveEffect(EffectType type, int amount){
        switch(type) {
            case DAMAGE:
                std::cout << _name << " took " << amount << " Damage" << std::endl;
                _hp -= amount;
                break;
            case HEAL:
                std::cout << _name << "'s HP got increased by " << amount << std::endl;
                _hp += amount;
                break;
        }

}

void Character::performSkill(ISkillUser* target){
    int index;
    std::cout << "Give in which skill you want to use:" << std::endl;
    std::cin >> index;
    std::cout << _name << " uses ";
    _class->getSkills()[index]->use(target);

}
