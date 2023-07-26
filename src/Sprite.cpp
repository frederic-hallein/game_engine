#include <iostream>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "headers/Sprite.hpp"

Sprite::Sprite() {}

Sprite::~Sprite() 
{
    clear();
    std::cout << "Sprite destroyed" << std::endl;
}

void Sprite::init(SDL_Renderer* renderer, const char* path_name)
{
    surface = IMG_Load(path_name);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    std::cout << "Sprite init" << std::endl;

}

void Sprite::clear() 
{
    SDL_DestroyTexture(texture);
    std::cout << "Sprite cleared" << std::endl;
}

SDL_Texture* Sprite::getTexture() {return texture;}
