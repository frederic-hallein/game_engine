#include <iostream>

#include "headers/Player.hpp"

Player::Player() 
{
    mass = 100.0f;
    acceleration.x = 0.0f;
    terminal_velocity.x = 10.0f;
    terminal_velocity.y = 15.0f;
}

Player::~Player() {std::cout << "Player destroyed" << std::endl;}

void Player::handleEvents(SDL_Event event)
{


    switch(event.type){
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
        case SDLK_q:
            move = Move::LEFT;
            break;
        case SDLK_d:
            move = Move::RIGHT;
            break;
        case SDLK_SPACE:
            action = Action::JUMP;
            break;
        default:
            break;
        }
        break;


    case SDL_KEYUP:
        switch(event.key.keysym.sym){
        case SDLK_q:
            move = Move::NONE;
            break;
        case SDLK_d:
            move = Move::NONE;
            break;
        case SDLK_SPACE:
            action = Action::NO_JUMP;
            hasJumped = false;
            break;
        default:
            break;
        }
        break;

    default:
        break;

            
    } 
}

void Player::update()
{

    Entity::update();

    switch (move){
    case Move::NONE:
        //std::cout << "NONE" << '\n';
        if (velocity.x < 0.0f)
        {
            acceleration.x = 0.0f;
            velocity.x += friction.x;
            if (velocity.x >= 0.0f) {velocity.x = 0.0f;}
        }
        else if (velocity.x > 0.0f)
        {
            acceleration.x = 0.0f;
            velocity.x -= friction.x;
            if (velocity.x <= 0.0f) {velocity.x = 0.0f;}
        }
        else {acceleration.x = 0.0f;}        
        break;
    case Move::LEFT:
        lookingRight = false;
        //std::cout << "LEFT" << '\n';
        acceleration.x = -1.0f;
        if (velocity.x <= -terminal_velocity.x) {velocity.x = -terminal_velocity.x;}
        break;
    case Move::RIGHT:
        lookingRight = true;
        //std::cout << "RIGHT" << '\n';
        acceleration.x = 1.0f;
        if (velocity.x >= terminal_velocity.x) {velocity.x = terminal_velocity.x;} 
        break;

    default:
        break;
    }


    switch (action){
    case Action::NO_JUMP:
        //std::cout << "NO JUMP" << '\n';
        if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}
        else {acceleration.y = 0.0f;}
        break;

    case Action::JUMP:
        if ((hitGround || amount_jumps > 0) && !hasJumped) 
        {
            //std::cout << "JUMP" << '\n';
            acceleration.y = -20.0f; 
            amount_jumps--;
            std::cout << amount_jumps << '\n';
            hitGround = false;
            hasJumped = true;
        }
        else {acceleration.y = 0.0f;}
        break;
        
    default:
        break;
    } 

}