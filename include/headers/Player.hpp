#pragma once

#include "headers/Entity.hpp"
#include "headers/Texture.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    
    void handleEvents(SDL_Event event) override;
    void update() override;

    enum Direction {NONE, LEFT, RIGHT, JUMP};

private:
    Direction direction;

};


