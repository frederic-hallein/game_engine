#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>

#include "SpriteManager.hpp"
#include "Vector2D.hpp"

class Sprite : public SpriteManager{
public:
    Sprite();
    ~Sprite();

    void init(SDL_Renderer* renderer, const char* path_name,
            int position_x, int position_y, int dst_rect_w, int dst_rect_h,
            int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h);

    
    void update();
    void flip();
    void draw();
    void clear();


    SDL_Rect src_rect;
    SDL_Rect dst_rect;

    Vector2D<float> position;
    
    Vector2D<float> bottom_center;
    Vector2D<float> bottom_right;
    Vector2D<float> bottom_left;
    Vector2D<float> middle_right;
    Vector2D<float> middle_left;
    Vector2D<float> top_center;
    Vector2D<float> top_right;
    Vector2D<float> top_left;

    bool flipHorizontal;

private:
    SDL_Renderer* renderer;

    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;


};