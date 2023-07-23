#include <iostream>

#include "headers/Player.hpp"

Player::Player() {}

Player::~Player() {std::cout << "Player destroyed" << std::endl;}

void Player::handleEvents(SDL_Event event)
{
    switch(event.type){
    case SDL_KEYDOWN:
        {
        Uint8 const* keys = SDL_GetKeyboardState(nullptr);
        if(keys[SDL_SCANCODE_A] == 1)
            direction = Direction::LEFT;
        else if(keys[SDL_SCANCODE_D] == 1)
            direction = Direction::RIGHT;
        else if(keys[SDL_SCANCODE_SPACE] == 1)
            direction = Direction::JUMP;
        break;
        }
    case SDL_KEYUP:
        {
        Uint8 const* keys = SDL_GetKeyboardState(nullptr);
        if(keys[SDL_SCANCODE_A] == 0)
            direction = Direction::NONE;
        else if(keys[SDL_SCANCODE_D] == 0)
            direction = Direction::NONE;
        else if(keys[SDL_SCANCODE_SPACE] == 0)
            direction = Direction::NONE;
        break;
        }
            
    }
}

void Player::update()
{
    Entity::update();

    switch (direction){
    case Direction::NONE:
        break;
    case Direction::LEFT:
        std::cout << "LEFT" << '\n';
        x_pos -= 10;
        break;
    case Direction::RIGHT:
        std::cout << "RIGHT" << '\n';
        x_pos += 10;
        break;
    case Direction::JUMP:
        std::cout << "JUMP" << '\n';
        break;
    }
}