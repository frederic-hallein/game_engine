#pragma once

#include "headers/Entity.hpp"
#include "headers/Texture.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    
    void handleEvents(SDL_Event event);
    void update();

    enum Direction {NONE, LEFT, RIGHT, JUMP};

private:
    Direction direction;

};


