#include "Fighter.h"

Fighter::Fighter()
{
    skills[0] = new Slash();
    skills[1] = new Amputation();
}

Fighter::~Fighter()
{

}
