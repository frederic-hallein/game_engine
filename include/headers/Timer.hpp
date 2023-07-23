#pragma once

class FPSTimer{
public:
    FPSTimer();
    ~FPSTimer();

    void start();
    void stop();

private:
    uint32_t frame_start;
    int frame_time;
};