#include <iostream>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "headers/Texture.hpp"

Texture::Texture() {}

Texture::~Texture() 
{
    clear();
    std::cout << "Texture destroyed" << std::endl;
}

void Texture::init(SDL_Renderer* renderer, const char* path_name)
{
    SDL_surface = IMG_Load(path_name);
    SDL_texture = SDL_CreateTextureFromSurface(renderer, SDL_surface);
    SDL_FreeSurface(SDL_surface);

    std::cout << "Texture init" << std::endl;

}

void Texture::clear() 
{
    SDL_DestroyTexture(SDL_texture);
    std::cout << "Texture cleared" << std::endl;
}

SDL_Texture* Texture::getTexture() {return SDL_texture;}
