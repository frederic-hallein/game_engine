#pragma once

template <typename T>
struct Vector2D {
    Vector2D(T x = 0, T y = 0);
    ~Vector2D();

    T x, y;    
};