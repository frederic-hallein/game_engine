#pragma once

#include <SDL2/SDL.h>

class Sprite {
public:
    Sprite();
    ~Sprite();

    void init(SDL_Renderer* renderer, const char* path_name);
    void clear();

    SDL_Texture* getTexture();
private:
    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;
};