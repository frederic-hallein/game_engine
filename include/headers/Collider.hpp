#pragma once

#include <SDL2/SDL.h>

#include "headers/Vector2D.hpp"

class Collider {
public:
    Collider();
    ~Collider();

    void init(SDL_Renderer* renderer, int position_x, int position_y, int dst_rect_w, int dst_rect_h);

    void update();
    void draw();
    void disable();

    SDL_Rect coll_rect;

    Vector2D position;

    float delta_w = 0.0f;
    float delta_h = 0.0f;
    
    Vector2D bottom_center;
    Vector2D bottom_right;
    Vector2D bottom_left;
    Vector2D top_center;
    Vector2D top_right;
    Vector2D top_left;

private:
    SDL_Renderer* renderer;


};