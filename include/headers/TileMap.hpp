#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TileMap {
public:
    TileMap();
    ~TileMap();

    void init(SDL_Renderer* renderer, const char* path_name);
    void update();
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture = nullptr;


private:
    SDL_Surface* surface = nullptr;
};