#include <iostream>

#include "Game.hpp"
#include "Timer.hpp"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;


int main(int argc, char* argv[])
{
    Game game;
    game.init("2D Platformer", SCREEN_WIDTH, SCREEN_HEIGHT, false);

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
