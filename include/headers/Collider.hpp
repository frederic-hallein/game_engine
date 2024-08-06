#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

#include "Vector2D.hpp"

class Collider {
public:
    Collider();
    ~Collider();

    void init(SDL_Renderer* renderer, int position_x, int position_y, int dst_rect_w, int dst_rect_h);

    void update();
    void draw();
    void disable();

    SDL_Rect coll_rect;

    Vector2D<float> position;

    float delta_w;
    float delta_h;

    Vector2D<float> bottom_center;
    Vector2D<float> bottom_right;
    Vector2D<float> bottom_left;
    Vector2D<float> middle_right;
    Vector2D<float> middle_left;
    Vector2D<float> top_center;
    Vector2D<float> top_right;
    Vector2D<float> top_left;

private:
    SDL_Renderer* renderer;


};