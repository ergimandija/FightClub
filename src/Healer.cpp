#include "Healer.h"

Healer::Healer()
{
    skills[0] = new Heal();
    skills[1] = new Revive();
}

Healer::~Healer()
{

}
