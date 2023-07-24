#include <iostream>

#include "headers/Player.hpp"

Player::Player() 
{
    mass = 100.0f;
    acceleration.x = 0.0f;
    terminal_velocity.x = 10.0f;
    terminal_velocity.y = 10.0f;
}

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
        {
        if (velocity.x < 0.0f)
        {
            acceleration.x = friction.x;
            if (velocity.x >= 0.0f) {velocity.x = 0.0f;}
        }
        else if (velocity.x > 0.0f)
        {
            acceleration.x = -friction.x;
            if (velocity.x <= 0.0f) {velocity.x = 0.0f;}
        }
        else {acceleration.x = 0.0f;}
        break;
        }
    case Direction::LEFT:
        {
        acceleration.x = -1.0f;
        if (velocity.x <= -terminal_velocity.x) {velocity.x = -terminal_velocity.x;}
        break;
        }
    case Direction::RIGHT:
        {
        acceleration.x = 1.0f;
        if (velocity.x >= terminal_velocity.x) {velocity.x = terminal_velocity.x;} 
        break;
        }
    case Direction::JUMP:
        {
        //std::cout << "JUMP" << '\n';
        break;
        }
    }

}