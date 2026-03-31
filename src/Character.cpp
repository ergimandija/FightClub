#include "Character.h"

Character::Character(std::string name, int hp,  CharacterClass* chclass)
{
    _name = name;
    _hp = hp;
    _class = chclass;
    _isAlive = true;
}

Character::~Character()
{
    delete _class;
}

void Character::recieveEffect(EffectType type, int amount){
        switch(type) {
            case DAMAGE:
                std::cout << _name << " took " << amount << " Damage" << std::endl;
                _hp -= amount;
                break;
            case HEAL:
                std::cout << _name << "'s HP got healed by " << amount << std::endl;
                _hp += amount;
                break;
            case REVIVE:
                if(_isAlive){
                     std::cout << _name << " is alive but got Healed by " << amount << std::endl;
                    _hp += amount;
                } else {
                    std::cout << _name << "got revived! his hp is now " << amount << std::endl;
                    _hp += amount;
                    _isAlive = true;
                }
                break;

        }

}

void Character::performSkill(BattleContext& ctx){
    int index;
    bool finished=false;
    while(!finished){
    std::cout << "Give in which skill you want to use:" << std::endl;
    std::cin >> index;

    if(index >= 2 || index < 0){
        std::cout << "Index invalid please give 0 or 1 for the Skills" << std::endl;
    } else {
    std::cout << _name << " uses ";
    _class->getSkills()[index]->use(this,ctx);
    finished = true;
    }
    }
}


bool Character::isAlive() const{
    return _isAlive;
}


std::string Character::getName() const {
     return _name;
}
