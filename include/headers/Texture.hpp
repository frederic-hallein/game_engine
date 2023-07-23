#pragma once

#include <SDL2/SDL.h>

class Texture {
public:
    Texture();
    ~Texture();

    void init(SDL_Renderer* renderer, const char* path_name);
    void clear();

    SDL_Texture* getTexture();
private:
    SDL_Surface* SDL_surface = nullptr;
    SDL_Texture* SDL_texture = nullptr;
};