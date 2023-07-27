#include <iostream>

#include "headers/Collider.hpp"

Collider::Collider() {}

Collider::~Collider() {}


void Collider::init(SDL_Renderer* renderer, int position_x, int position_y, int dst_rect_w, int dst_rect_h)
{
    this->renderer = renderer;

    position.x = position_x;
    position.y = position_y;

    // setup rectangle positions wrt to (x,y) position
    bottom_center.x = position_x;
    bottom_center.y = position_y + dst_rect_h / 2 - delta_h;

    bottom_left.x = position_x - dst_rect_w / 2 + delta_w;
    bottom_left.y = position_y + dst_rect_h / 2 - delta_h;

    bottom_right.x = position_x + dst_rect_w / 2 - delta_w;
    bottom_right.y = position_y + dst_rect_h / 2 - delta_h;

    top_center.x = position_x;
    top_center.y = position_y - dst_rect_h / 2 + delta_h;

    top_left.x = position_x - dst_rect_w / 2 + delta_w;
    top_left.y = position_y - dst_rect_h / 2 + delta_h;

    top_right.x = position_x + dst_rect_w / 2 - delta_w;
    top_right.y = position_y - dst_rect_h / 2 + delta_h;

    // destination rectangle
    coll_rect.x = top_left.x - delta_w;
    coll_rect.y = top_right.y - delta_h;
    coll_rect.w = dst_rect_w - delta_w;
    coll_rect.h = dst_rect_h - delta_h;

    std::cout << "Collider init" << std::endl;

}

void Collider::update()
{
    // update collider rectangle 
    bottom_center.x = position.x;
    bottom_center.y = position.y + coll_rect.h / 2 - delta_h;

    bottom_left.x = position.x - coll_rect.w / 2 + delta_w;
    bottom_left.y = position.y + coll_rect.h / 2 - delta_h;

    bottom_right.x = position.x + coll_rect.w / 2 - delta_w;
    bottom_right.y = position.y + coll_rect.h / 2 - delta_h;

    top_center.x = position.x;
    top_center.y = position.y - coll_rect.h / 2 + delta_h;

    top_left.x = position.x - coll_rect.w / 2 + delta_w;
    top_left.y = position.y - coll_rect.h / 2 + delta_h;

    top_right.x = position.x + coll_rect.w / 2 - delta_w;
    top_right.y = position.y - coll_rect.h / 2 + delta_h;

    // collider rectangle
    coll_rect.x = top_left.x - delta_w;
    coll_rect.y = top_right.y - delta_h;
}

void Collider::draw()
{
    // draw rect of collider
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &coll_rect);
}



void Collider::disable() 
{
    std::cout << "Collider disabled" << std::endl;
}