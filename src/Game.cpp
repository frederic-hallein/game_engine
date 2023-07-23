#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "headers/Game.hpp"


Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    // initiatlize window and renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "SDL_Init has failed." << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl; 
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << "Could not create window." << std::endl;
        std::cout << "Error: " << SDL_GetError() <<std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::cout << "Could not create renderer." << std::endl;
        std::cout << "Error: " << SDL_GetError() <<std::endl;
    }

    // initialize player
    int sprite_section = 64;
    int sprite_size = 64;
    player.init(renderer, "assets/player/player.png", 0, 0, sprite_section, sprite_section, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, sprite_size, sprite_size);
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    player.handleEvents(event);
    switch (event.type){
        case SDL_QUIT:
            is_running = false;   
            break;

        default:
            break;
    }
}

void Game::update()
{

    player.update();
}

void Game::render()
{

    SDL_RenderClear(renderer);
    player.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() {return is_running;}

