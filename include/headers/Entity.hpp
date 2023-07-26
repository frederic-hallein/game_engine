#pragma once

#include <SDL2/SDL.h>

#include "headers/Sprite.hpp"
#include "headers/Collider.hpp"
#include "headers/Vector2D.hpp"

static Vector2D gravity(0.0f, 1.0f);
static Vector2D friction(0.5f, 0.0f);


class Entity {
public:
    Entity();
    ~Entity();

    void init(SDL_Renderer* renderer, const char* path_name, 
            int position_x, int position_y, int dst_rect_w, int dst_rect_h,
            int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h);
    
    void draw();

    void handleEvents(SDL_Event event);
    void update();
    void printInfo();

    void updateSpriteRectPosition();
    void updateColliderPosition();

    bool hasJumped = false;
    bool hitGround = false;
    bool lookingRight = true;
protected:
    SDL_Rect sprite_src_rect;
    SDL_Rect sprite_dst_rect;
    SDL_Rect coll_rect;

    float mass;
    Vector2D position;
    Vector2D velocity;
    Vector2D terminal_velocity;
    Vector2D acceleration;
    Vector2D force;

    Vector2D sprite_bottom_center;
    Vector2D sprite_bottom_right;
    Vector2D sprite_bottom_left;
    Vector2D sprite_top_center;
    Vector2D sprite_top_right;
    Vector2D sprite_top_left;

    
private:
    SDL_Renderer* renderer;
    Sprite sprite;


};