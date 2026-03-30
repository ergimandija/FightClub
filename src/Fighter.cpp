#include "Fighter.h"

Fighter::Fighter()
{
    skills[0] = new Slash();
    skills[1] = new FireBall();
}

Fighter::~Fighter()
{
    for (int i = 0; i < 2; i++) {
        delete skills[i];
    }
}
