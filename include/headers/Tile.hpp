#pragma once

#include "headers/TileMap.hpp"
#include "headers/Collider.hpp"

class Tile : public TileMap {
public:
    Tile();
    ~Tile();

    void init();
    void update();
    void draw();
private:
    

    SDL_Rect src_rect;
    SDL_Rect dst_rect;

    Collider collider;
};