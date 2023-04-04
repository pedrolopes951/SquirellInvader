#include "Game.hpp"
#include "time.h"

int main(void)
{

    // Init Game 
    srand(time(static_cast<unsigned>(0)));
    
    // Init Game object 

    Game game;

    // Game Loop
    game.run();

    return 0 ;

}