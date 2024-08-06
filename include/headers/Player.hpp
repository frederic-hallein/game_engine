#pragma once

#include <iostream>

#include "Entity.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    
    void handleEvents(SDL_Event event);
    void update();

private:

    int jump_count = 2;

    Vector2D<float> player_acceleration;

};


