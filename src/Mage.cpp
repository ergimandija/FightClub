#include "Mage.h"

Mage::Mage()
{
    skills[0] = new FireBall();
    skills[1] = new Lightning();
}

Mage::~Mage()
{

}
