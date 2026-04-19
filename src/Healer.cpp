#include "Healer.h"

Healer::Healer()
{
    _texturePath = "sprites/Healer";
    skills[0] = new Heal();
    skills[1] = new Revive();
}

Healer::~Healer()
{

}
