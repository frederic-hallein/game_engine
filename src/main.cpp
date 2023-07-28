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

    Timer timer; 
    while (game.running()){
        timer.start();

        game.handleEvents();
        game.render();
        game.update();

        timer.stop();
        timer.delayFrame();
    }

    game.clean();
    return 0;
}
