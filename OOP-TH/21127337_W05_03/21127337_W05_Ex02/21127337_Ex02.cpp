#include "Game.h"

int main()
{
    // srand is used to initialize random number generators, we seed the time as null so the rand() function will output different numbers.
    srand(time(NULL));
    Game g;
    g.playGame();
    return 0;
}