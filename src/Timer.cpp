#include <SDL2/SDL.h>

#include "headers/Timer.hpp"

static const int FPS = 60;
static const int frame_delay = 1000 / FPS;

FPSTimer::FPSTimer() {}

FPSTimer::~FPSTimer() {}

void FPSTimer::start()
{
    frame_start = SDL_GetTicks();
}

void FPSTimer::stop()
{
    frame_time = SDL_GetTicks() - frame_start;
    if (frame_delay > frame_time) {SDL_Delay(frame_delay - frame_time);}
}
