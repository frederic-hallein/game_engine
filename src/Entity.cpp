#include <iostream>

#include "headers/Entity.hpp"

Entity::Entity() {}

Entity::~Entity() {std::cout << "Entity destroyed" << std::endl;}

void Entity::init(SDL_Renderer* renderer, const char* path_name,
                int position_x, int position_y, int dst_rect_w, int dst_rect_h,
                int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h)
{
    this->renderer = renderer;

    sprite.init(renderer, path_name);

    // setup entity position
    position.x = position_x;
    position.y = position_y;

    // setup rectangle positions wrt to (x,y) position
    bottom_center.x = position_x;
    bottom_center.y = position_y + dst_rect_h / 2;

    bottom_left.x = position_x - dst_rect_w / 2;
    bottom_left.y = position_y + dst_rect_h / 2;

    bottom_right.x = position_x + dst_rect_w / 2;
    bottom_right.y = position_y + dst_rect_h / 2;

    top_center.x = position_x;
    top_center.y = position_y - dst_rect_h / 2;

    top_left.x = position_x - dst_rect_w / 2;
    top_left.y = position_y - dst_rect_h / 2;

    top_right.x = position_x + dst_rect_w / 2;
    top_right.y = position_y - dst_rect_h / 2;

    // setup rectangle for rendering texture
    // source rectangle
    src_rect.x = src_rect_x; 
    src_rect.y = src_rect_y; 
    src_rect.w = src_rect_w; 
    src_rect.h = src_rect_h; 

    // destination rectangle
    dst_rect.x = top_left.x;
    dst_rect.y = top_right.y;
    dst_rect.w = dst_rect_w;
    dst_rect.h = dst_rect_h;

    std::cout << "Entity init" << std::endl;
}

void Entity::draw()
{
    SDL_RenderClear(renderer);

    // flip player sprite
    if (lookingRight)
    {
        SDL_RenderCopyEx(renderer, sprite.getTexture(), &src_rect, &dst_rect, 0, nullptr, SDL_FLIP_NONE);
    }
    else 
    {
        SDL_RenderCopyEx(renderer, sprite.getTexture(), &src_rect, &dst_rect, 0, nullptr, SDL_FLIP_HORIZONTAL);       
    }


    // game object axis
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &dst_rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + dst_rect.w, position.y);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x, position.y - dst_rect.h);
    // gameobject force vector
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + 10 * velocity.x, position.y + 10 * velocity.y);
}

void Entity::handleEvents(SDL_Event event) {}

void Entity::update() 
{
    // reset net force
    force.x = 0.0f;
    force.y = 0.0;

    // apply gravity
    force.y += mass * (gravity.y + acceleration.y);
    velocity.y += force.y * (1.0f / mass);
    if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}
    position.y += velocity.y;
    
    // apply movement
    force.x += mass * acceleration.x;
    velocity.x += force.x * (1.0f / mass);
    position.x += velocity.x;
    
    updateRectanglePosition();

    if (bottom_center.y < 600.0f)
    {
        hitGround = false;
        // move rect
        dst_rect.y = top_left.y; 
        dst_rect.x = top_left.x;
    }
    else
    {
        position.y = 600.0f - dst_rect.h / 2;
        velocity.y = 0.0f;
        updateRectanglePosition();
        hitGround = true;

        dst_rect.y = top_left.y; 
        dst_rect.x = top_left.x;
    }

 

    //Entity::printInfo();

    
    
}

void Entity::printInfo()
{
    std::cout << "F: " << "(" << force.x << ", " << force.y << ") ";
    std::cout << "acc: " << "(" << acceleration.x << ", " << acceleration.y << ") ";
    std::cout << "vel: " << "(" << velocity.x << ", " << velocity.y << ") ";
    std::cout << "pos: " << "(" << position.x << ", " << position.y << ") " << '\n';
}

void Entity::updateRectanglePosition()
{

    // update destination rectangle 
    bottom_center.x = position.x;
    bottom_center.y = position.y + dst_rect.h / 2;

    bottom_left.x = position.x - dst_rect.w / 2;
    bottom_left.y = position.y + dst_rect.h / 2;

    bottom_right.x = position.x + dst_rect.w / 2;
    bottom_right.y = position.y + dst_rect.h / 2;

    top_center.x = position.x;
    top_center.y = position.y - dst_rect.h / 2;

    top_left.x = position.x - dst_rect.w / 2;
    top_left.y = position.y - dst_rect.h / 2;

    top_right.x = position.x + dst_rect.w / 2;
    top_right.y = position.y - dst_rect.h / 2;
}