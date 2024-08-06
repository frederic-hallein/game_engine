#include "Player.hpp"

Player::Player() 
{
    // setup collider resize
    collider.delta_w = 15.0f;
    collider.delta_h = 0.0f;

    // player characteristics
    mass = 100.0f;
    terminal_velocity.x = 10.0f;
    terminal_velocity.y = 20.0f;

    player_acceleration.x = 1.0f;
    player_acceleration.y = 20.0f;
}

Player::~Player() {std::cout << "Player destroyed" << std::endl;}

void Player::handleEvents(SDL_Event event)
{
    switch(event.type){
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
        case SDLK_q:
            move = Move::MOVE_LEFT;
            break;
        case SDLK_d:
            move = Move::MOVE_RIGHT;
            break;
        case SDLK_SPACE:
            jump = Jump::JUMP;
            break;
        default:
            break;
        }
        break;


    case SDL_KEYUP:
        switch(event.key.keysym.sym){
        case SDLK_q:
            move = Move::NO_MOVE;
            break;
        case SDLK_d:
            move = Move::NO_MOVE;
            break;
        case SDLK_SPACE:
            jump = Jump::NO_JUMP;
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
    case Move::NO_MOVE:
        /* std::cout << "NO MOVE" << '\n'; */
        if (velocity.x < 0.0f)
        {
            acceleration.x = friction.x;
            if (velocity.x + acceleration.x > 0.0f) {acceleration.x = 0.0f; velocity.x = 0.0f;}
        }
        else if (velocity.x > 0.0f)
        {
            acceleration.x = -friction.x;
            if (velocity.x + acceleration.x < 0.0f) {acceleration.x = 0.0f; velocity.x = 0.0f;}
        }
        else {acceleration.x = 0.0f; velocity.x = 0.0f;}        
        break;
    case Move::MOVE_LEFT:
        lookingRight = false;
        /* std::cout << "MOVE LEFT" << '\n'; */
        acceleration.x = -player_acceleration.x;
        if (velocity.x <= -terminal_velocity.x) {velocity.x = -terminal_velocity.x;}
        break;
    case Move::MOVE_RIGHT:
        lookingRight = true;
        /* std::cout << "MOVE RIGHT" << '\n'; */
        acceleration.x = player_acceleration.x;
        if (velocity.x >= terminal_velocity.x) {velocity.x = terminal_velocity.x;} 
        break;

    default:
        break;
    }


    switch (jump){
    case Jump::NO_JUMP:
        /* std::cout << "NO JUMP" << '\n'; */
        if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}
        else {acceleration.y = 0.0f;}
        break;

    case Jump::JUMP:
        // reset jump count
        if (hitGround && jump_count <= 1) {jump_count = 2;} 

        // single jump
        if (hitGround && !hasJumped) 
        {
            /* std::cout << "JUMP" << '\n'; */
            acceleration.y = -player_acceleration.y;
            
            jump_count--;

            hitGround = false;
            hasJumped = true;
        }
        // double jump
        else if (!hitGround && !hasJumped && jump_count > 0)
        {
            /* std::cout << "JUMP" << '\n'; */
            // limit vertical acceleration when space bar pressed consecutively after each other
            velocity.y = 0.0f;
            acceleration.y = -player_acceleration.y;
            
            jump_count--;

            hitGround = false;
            hasJumped = true;
        }
        else {acceleration.y = 0.0f;} // no space bar hold

        break;
        
    default:
        break;
    } 

}