#include <iostream>

#include "headers/Entity.hpp"


Entity::Entity() {}

Entity::~Entity() {std::cout << "Entity destroyed" << std::endl;}

void Entity::init(SDL_Renderer* renderer, const char* path_name,
                int position_x, int position_y, int dst_rect_w, int dst_rect_h,
                int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h)
{
    this->renderer = renderer;

    // setup entity position
    position.x = position_x;
    position.y = position_y;

    // setup sprite
    sprite.init(renderer, path_name, 
                position_x, position_y, dst_rect_w, dst_rect_h,
                src_rect_x, src_rect_y, src_rect_w, src_rect_h);

    sprite_src_rect = sprite.src_rect;
    sprite_dst_rect = sprite.dst_rect;

    sprite_bottom_center = sprite.bottom_center;
    sprite_bottom_right = sprite.bottom_right;
    sprite_bottom_left = sprite.bottom_left;
    sprite_top_center = sprite.top_center;
    sprite_top_right = sprite.top_right;
    sprite_top_left = sprite.top_left;

    std::cout << "Entity init" << std::endl;
}

void Entity::draw()
{
    SDL_RenderClear(renderer);

    // flip player sprite
    if (lookingRight)
    {
        SDL_RenderCopyEx(renderer, sprite.getTexture(), &sprite_src_rect, &sprite_dst_rect, 0, nullptr, SDL_FLIP_NONE);
    }
    else 
    {
        SDL_RenderCopyEx(renderer, sprite.getTexture(), &sprite_src_rect, &sprite_dst_rect, 0, nullptr, SDL_FLIP_HORIZONTAL);       
    }

    // sprite rect
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &sprite_dst_rect);

    // entity axis
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + sprite_dst_rect.w, position.y);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x, position.y - sprite_dst_rect.h);
    // entity force vector
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + 10 * velocity.x, position.y + 10 * velocity.y);
}

void Entity::handleEvents(SDL_Event event) {}

void Entity::update() 
{

    // forces x direction
    force.y += mass * (gravity.y + acceleration.y);
    velocity.y += force.y * (1.0f / mass);
    if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}

    position.y += velocity.y;
    sprite.position.y += velocity.y;
    
    // forces y direction
    force.x += mass * acceleration.x;
    velocity.x += force.x * (1.0f / mass);

    position.x += velocity.x;
    sprite.position.x += velocity.x;
    
    // update sprite //TODO: make sprite.draw() method
    sprite.update();
    sprite_bottom_center = sprite.bottom_center;
    sprite_bottom_right = sprite.bottom_right;
    sprite_bottom_left = sprite.bottom_left;
    sprite_top_center = sprite.top_center;
    sprite_top_right = sprite.top_right;
    sprite_top_left = sprite.top_left;


    if (sprite_bottom_center.y < 600.0f)
    {
        hitGround = false;
        
        // move rect
        sprite_dst_rect.y = sprite_top_left.y; 
        sprite_dst_rect.x = sprite_top_left.x;
    }
    else
    {
        position.y = 600.0f - sprite_dst_rect.h / 2;
        sprite.position.y = 600.0f - sprite_dst_rect.h / 2;
        
        velocity.y = 0.0f;
        
        sprite.update();
        sprite_bottom_center = sprite.bottom_center;
        sprite_bottom_right = sprite.bottom_right;
        sprite_bottom_left = sprite.bottom_left;
        sprite_top_center = sprite.top_center;
        sprite_top_right = sprite.top_right;
        sprite_top_left = sprite.top_left;

        hitGround = true;

        sprite_dst_rect.y = sprite_top_left.y; 
        sprite_dst_rect.x = sprite_top_left.x;
    }

 

    Entity::printInfo();

    // reset net force
    force.x = 0.0f;
    force.y = 0.0;


    
    
}

void Entity::printInfo()
{
    std::cout << "F: " << "(" << force.x << ", " << force.y << ") ";
    std::cout << "acc: " << "(" << acceleration.x << ", " << acceleration.y << ") ";
    std::cout << "vel: " << "(" << velocity.x << ", " << velocity.y << ") ";
    std::cout << "pos: " << "(" << position.x << ", " << position.y << ") " << '\n';
}

