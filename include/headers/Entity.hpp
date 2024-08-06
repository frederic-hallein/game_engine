#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Sprite.hpp"
#include "Collider.hpp"
#include "Vector2D.hpp"

static Vector2D<float> gravity(0.0f, 1.0f);
static Vector2D<float> friction(0.7f, 0.0f);


class Entity {
public:
    Entity();
    ~Entity();

    void init(SDL_Renderer* renderer, const char* path_name, 
            int position_x, int position_y, int dst_rect_w, int dst_rect_h,
            int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h);
    

    void handleEvents(SDL_Event event);
    void update();
    void draw();
    void printInfo();

    enum Move {NO_MOVE, MOVE_LEFT, MOVE_RIGHT};
    enum Jump {NO_JUMP, JUMP};

protected:

    Move move;
    Jump jump;

    bool hasJumped = false;
    bool hitGround = false;
    bool lookingRight = true;

    SDL_Rect coll_rect;

    float mass;
    Vector2D<float> position;
    Vector2D<float> velocity;
    Vector2D<float> terminal_velocity;
    Vector2D<float> acceleration;
    Vector2D<float> force;
    
    Collider collider;
    
private:
    SDL_Renderer* renderer;
    
    Sprite sprite;




};