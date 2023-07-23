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

    src_rect.x = src_rect_x; dst_rect.x = dst_rect_x;
    src_rect.y = src_rect_y; dst_rect.y = dst_rect_y;
    src_rect.w = src_rect_w; dst_rect.w = dst_rect_w;
    src_rect.h = src_rect_h; dst_rect.h = dst_rect_h;

    std::cout << "Entity init" << std::endl;
}

void Entity::draw()
{
    SDL_RenderCopy(renderer, texture.getTexture(), &src_rect, &dst_rect);
}

void Entity::handleEvents(SDL_Event event) {}

void Entity::update() {}