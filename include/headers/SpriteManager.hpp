#pragma once

class SpriteManager {
public:
    SpriteManager();
    ~SpriteManager();

    void init();
    void update();

protected:
    enum animation {IDLE, RUN, JUMP, FALL};

private:
};