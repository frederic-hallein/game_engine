#pragma once

#include "headers/Entity.hpp"
#include "headers/Sprite.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    
    void handleEvents(SDL_Event event);
    void update();

private:
    Move move;
    Jump jump;

    int jump_count = 2;

    Vector2D player_acceleration;

};


