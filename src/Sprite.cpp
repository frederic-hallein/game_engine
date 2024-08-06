#include "Sprite.hpp"

Sprite::Sprite() {}

Sprite::~Sprite() 
{
    clear();
    std::cout << "Sprite destroyed" << std::endl;
}

void Sprite::init(SDL_Renderer* renderer, const char* path_name,
                int position_x, int position_y, int dst_rect_w, int dst_rect_h,
                int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h)
{
    this->renderer = renderer;

    surface = IMG_Load(path_name);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    position.x = position_x;
    position.y = position_y;

    // setup rectangle positions wrt to (x,y) position
    bottom_center.x = position_x;
    bottom_center.y = position_y + dst_rect_h / 2;

    bottom_left.x = position_x - dst_rect_w / 2;
    bottom_left.y = position_y + dst_rect_h / 2;

    bottom_right.x = position_x + dst_rect_w / 2;
    bottom_right.y = position_y + dst_rect_h / 2;

    middle_left.x = position_x - dst_rect_w / 2;
    middle_left.y = position_y;

    middle_right.x = position_x + dst_rect_w / 2;
    middle_right.y = position_y;

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
    dst_rect.y = top_left.y;
    dst_rect.w = dst_rect_w;
    dst_rect.h = dst_rect_h;

    std::cout << "Sprite init" << std::endl;

}


void Sprite::update()
{
    // update destination rectangle 
    bottom_center.x = position.x;
    bottom_center.y = position.y + dst_rect.h / 2;

    bottom_left.x = position.x - dst_rect.w / 2;
    bottom_left.y = position.y + dst_rect.h / 2;

    bottom_right.x = position.x + dst_rect.w / 2;
    bottom_right.y = position.y + dst_rect.h / 2;

    middle_left.x = position.x - dst_rect.w / 2;
    middle_left.y = position.y;

    middle_right.x = position.x + dst_rect.w / 2;
    middle_right.y = position.y;

    top_center.x = position.x;
    top_center.y = position.y - dst_rect.h / 2;

    top_left.x = position.x - dst_rect.w / 2;
    top_left.y = position.y - dst_rect.h / 2;

    top_right.x = position.x + dst_rect.w / 2;
    top_right.y = position.y - dst_rect.h / 2;

    // destination rectangle
    dst_rect.x = top_left.x;
    dst_rect.y = top_left.y;


    flipHorizontal = false;

    
}

void Sprite::draw()
{
    
    // draw sprite 
    if (!flipHorizontal)
    {
        SDL_RenderCopyEx(renderer, texture, &src_rect, &dst_rect, 0, nullptr, SDL_FLIP_NONE);
    }
    else 
    {
        SDL_RenderCopyEx(renderer, texture, &src_rect, &dst_rect, 0, nullptr, SDL_FLIP_HORIZONTAL);
    }

    // draw rect of sprite
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &dst_rect);
}

void Sprite::flip()
{
    flipHorizontal = true;
}


void Sprite::clear() 
{
    SDL_DestroyTexture(texture);
    std::cout << "Sprite cleared" << std::endl;
}


