// this is the main file for a c++ sfml game
// @author Richard Prange, Suraj Sharma on yt
// @version 6/9/2025




#include "Game.h"


// allows us to not have sf:: before our sf::window etc
using namespace sf;

/**
 * The entry point to our program it does...
 *  
 */
int main(){
    

    //Our game 
    Game game; 

    // main loop
    while(game.isWinOpen()){

      game.update();

      game.render();
    }

    return 0;
}
