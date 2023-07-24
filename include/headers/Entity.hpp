#pragma once

#include <SDL2/SDL.h>

#include "headers/Texture.hpp"
#include "headers/Vector2D.hpp"

class Entity {
public:
    Entity();
    ~Entity();

    void init(SDL_Renderer* renderer, const char* path_name, 
            int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h,
            int dst_rect_x, int dst_rect_y, int dst_rect_w, int dst_rect_h);
    
    void draw();

    void handleEvents(SDL_Event event);
    void update();

protected:
    Vector2D pos;
    Vector2D vel;
    Vector2D force;
    float mass;
    
private:
    SDL_Renderer* renderer;
    SDL_Rect src_rect;
    SDL_Rect dst_rect;
    Texture texture;


};