#include <iostream>

#include "headers/Entity.hpp"

Entity::Entity() {}

Entity::~Entity() {std::cout << "Entity destroyed" << std::endl;}

void Entity::init(SDL_Renderer* renderer, const char* path_name,
                int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h,
                int dst_rect_x, int dst_rect_y, int dst_rect_w, int dst_rect_h)
{
    this->renderer = renderer;

    texture.init(renderer, path_name);

    // setup entity position
    position.x = dst_rect_x;
    position.y = dst_rect_y;

    // setup rectangle for rendering texture
    // source rectangle
    src_rect.x = src_rect_x; 
    src_rect.y = src_rect_y; 
    src_rect.w = src_rect_w; 
    src_rect.h = src_rect_h; 

    // destination rectangle
    dst_rect.x = position.x;
    dst_rect.y = position.y - dst_rect_h;
    dst_rect.w = dst_rect_w;
    dst_rect.h = dst_rect_h;

    std::cout << "Entity init" << std::endl;
}

void Entity::draw()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture.getTexture(), &src_rect, &dst_rect);
    
    // game object axis
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &dst_rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, dst_rect.x, dst_rect.y + dst_rect.h, dst_rect.x + 2 * dst_rect.w, dst_rect.y + dst_rect.h);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, dst_rect.x, dst_rect.y + dst_rect.h, dst_rect.x, dst_rect.y - dst_rect.h);
}

void Entity::handleEvents(SDL_Event event) {}

void Entity::update() 
{
    // apply gravity
    force.y += mass * gravity.y;
    velocity.y += force.y * (1.0f / mass);
    if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}
    position.y += velocity.y;
    
    dst_rect.y = position.y; // move rect

    // move
    force.x += mass * acceleration.x;
    velocity.x += force.x * (1.0f / mass);
    position.x += velocity.x;
    
    dst_rect.x = position.x; // move rect

    Entity::printInfo();

    // reset net force
    force.x = 0.0f;
    force.y = 0.0f;
}

void Entity::printInfo()
{
    std::cout << "F: " << "(" << force.x << ", " << force.y << ") ";
    std::cout << "acc: " << "(" << acceleration.x << ", " << acceleration.y << ") ";
    std::cout << "vel: " << "(" << velocity.x << ", " << velocity.y << ") ";
    std::cout << "pos: " << "(" << position.x << ", " << position.y << ") " << '\n';
}