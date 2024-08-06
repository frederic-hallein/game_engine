#include "Entity.hpp"


Entity::Entity() {}

Entity::~Entity() {std::cout << "Entity destroyed" << std::endl;}

void Entity::init(SDL_Renderer* renderer, const char* path_name,
                int position_x, int position_y, int dst_rect_w, int dst_rect_h,
                int src_rect_x, int src_rect_y, int src_rect_w, int src_rect_h)
{
    this->renderer = renderer;

    // setup entity position
    position.x = position_x;
    position.y = position_y;

    // setup sprite
    sprite.init(renderer, path_name, 
                position_x, position_y, dst_rect_w, dst_rect_h,
                src_rect_x, src_rect_y, src_rect_w, src_rect_h);

    // setup collider   
    collider.init(renderer, position_x, position_y, dst_rect_w, dst_rect_h);


    coll_rect = collider.coll_rect; // will not be necessary anymore when collision system is build


    std::cout << "Entity init" << std::endl;


    
}


void Entity::handleEvents(SDL_Event event) {}

void Entity::update() 
{
    // TODO : maybe make a physics class that do these calculations?
    // forces x direction
    force.x += mass * acceleration.x;
    velocity.x += force.x * (1.0f / mass);

    // forces y direction 
    force.y += mass * (gravity.y + acceleration.y);
    velocity.y += force.y * (1.0f / mass);
    if (velocity.y >= terminal_velocity.y) {velocity.y = terminal_velocity.y;}

    // TODO : do these checks in collider class or collider manager class?
    // update position of entity, sprite and collider
    position.x += velocity.x;
    position.y += velocity.y;
    sprite.position.x += velocity.x;
    sprite.position.y += velocity.y;
    collider.position.x += velocity.x;
    collider.position.y += velocity.y;

    // update sprite 
    sprite.update();
    // update collider
    collider.update();


    // TODO : tilemap system with colliders
    float ground = 720.0f;
    if (collider.bottom_center.y < ground) {hitGround = false;}
    else 
    {
        position.y = ground - collider.coll_rect.h / 2;
        sprite.position.y = position.y; 
        collider.position.y = position.y;
        
        acceleration.y = -gravity.y;
        velocity.y = 0.0f;

        hitGround = true;
    }


    // move collider rect
    coll_rect.y = collider.top_left.y; 
    coll_rect.x = collider.top_left.x;


    Entity::printInfo();

    // reset net force
    force.x = 0.0f;
    force.y = 0.0;

}


void Entity::draw()
{
    SDL_RenderClear(renderer);

    // draw sprite (flip if direction changed)
    if (!lookingRight) {sprite.flip();}
    sprite.draw();

    // draw collider
    collider.draw();

    // TODO : maybe make a GameObject parent class to Entity?

    // entity axis
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + 50, position.y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x, position.y - 50);
    // entity force vector
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, position.x, position.y, position.x + 10 * velocity.x, position.y + 10 * velocity.y);
}

void Entity::printInfo()
{
    std::cout << "F: " << "(" << force.x << ", " << force.y << ") ";
    std::cout << "acc: " << "(" << acceleration.x << ", " << gravity.y + acceleration.y << ") ";
    std::cout << "vel: " << "(" << velocity.x << ", " << velocity.y << ") ";
    std::cout << "pos: " << "(" << position.x << ", " << position.y << ") " << '\n';
}

