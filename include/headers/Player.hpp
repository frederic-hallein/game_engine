#pragma once

#include "headers/Entity.hpp"
#include "headers/Sprite.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    
    void handleEvents(SDL_Event event);
    void update();

    enum Move {NONE, LEFT, RIGHT};
    enum Action {NO_JUMP, JUMP};


private:
    int amount_jumps = 2;

    Move move;
    Action action;

};


