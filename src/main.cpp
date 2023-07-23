#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>

#include "headers/Game.hpp"
#include "headers/Timer.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char* argv[])
{
    Game game;
    game.init("2D Platformer", SCREEN_WIDTH, SCREEN_HEIGHT);

    FPSTimer FPStimer; 
    while (game.running()){
        FPStimer.start();
        game.handleEvents();
        game.update();
        game.render();
        FPStimer.stop();
        
    }

    game.clean();
    return 0;
}
