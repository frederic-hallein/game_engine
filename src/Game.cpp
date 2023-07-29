#include "headers/Game.hpp"


Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int SCREEN_WIDTH, int SCREEN_HEIGHT, bool fullscreen)
{
    int flags;
    if (fullscreen) {flags = SDL_WINDOW_FULLSCREEN;}
    else {flags = SDL_WINDOW_SHOWN;}


    // initiatlize window and renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "SDL_Init has failed." << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl; 
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (window == nullptr){
        std::cout << "Could not create window." << std::endl;
        std::cout << "Error: " << SDL_GetError() <<std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::cout << "Could not create renderer." << std::endl;
        std::cout << "Error: " << SDL_GetError() <<std::endl;
    }

    // TODO : initialize all entities, tiles, etc. in a level class

    // initialize player
    int sprite_section_x = 32;
    int sprite_section_y = 43;
    int sprite_scale = 1;
    player.init(renderer, "assets/player/player.png", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 
                sprite_section_x * sprite_scale, sprite_section_y * sprite_scale, 
                0, 0, sprite_section_x, sprite_section_y);

    // initialize tilemap

    //tilemap.init();

}

void Game::handleEvents()
{

    while (SDL_PollEvent(&event)){
        player.handleEvents(event);
        switch (event.type){
        case SDL_QUIT:
            is_running = false;   
            break;

        default:
            break;
        }
    }
}

void Game::update()
{
    player.update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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

