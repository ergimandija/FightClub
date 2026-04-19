#include "Fighter.h"

Fighter::Fighter()
{
    _texturePath = "sprites/Fighter";
    skills[0] = new Slash();
    skills[1] = new Amputation();
}

Fighter::~Fighter()
{

}
