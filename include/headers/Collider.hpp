#pragma once

#include <SDL2/SDL.h>


class Collider {
public:
    Collider();
    ~Collider();

    void init(SDL_Rect dst_rect);

    float x, y, w, h;


private:
    SDL_Rect collider;


};