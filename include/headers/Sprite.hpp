#pragma once

#include <SDL2/SDL.h>

#include "headers/Vector2D.hpp"

class Sprite {
public:
    Sprite();
    ~Sprite();

    void init(SDL_Renderer* renderer, const char* path_name,
            int position_x, int position_y, int dst_rect_w, int dst_rect_h,
            int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h);
    
    void update();
    void clear();

    SDL_Texture* getTexture();

    SDL_Rect src_rect;
    SDL_Rect dst_rect;

    Vector2D position;
    
    Vector2D bottom_center;
    Vector2D bottom_right;
    Vector2D bottom_left;
    Vector2D top_center;
    Vector2D top_right;
    Vector2D top_left;

private:
    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;


};