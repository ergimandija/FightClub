#include <iostream>
#include <time.h>
#include "Game.h"
using namespace std;

int main() {
    srand(time(NULL));
    Game game = Game();
    game.start();

    return 0;

}
