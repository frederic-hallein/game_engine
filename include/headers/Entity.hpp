#pragma once

#include <SDL2/SDL.h>

#include "headers/Texture.hpp"
#include "headers/Vector2D.hpp"

static Vector2D gravity(0.0f, 0.0f);
static Vector2D friction(0.5f, 0.0f);


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
    void printInfo();

protected:
    SDL_Rect src_rect;
    SDL_Rect dst_rect;

    Vector2D position;
    Vector2D velocity;
    Vector2D terminal_velocity;
    Vector2D acceleration;
    Vector2D force;
    float mass;
    
private:
    SDL_Renderer* renderer;
    Texture texture;


};