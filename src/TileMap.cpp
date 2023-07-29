#include "headers/TileMap.hpp"

TileMap::TileMap() {}

TileMap::~TileMap() {}

void TileMap::init(SDL_Renderer* renderer, const char* path_name)
{
    this->renderer = renderer;

    surface = IMG_Load(path_name);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void TileMap::update()
{

}
