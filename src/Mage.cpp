#include "Mage.h"

Mage::Mage()
{
    _texturePath = "sprites/Mage";
    skills[0] = new FireBall();
    skills[1] = new Lightning();
}

Mage::~Mage()
{

}
