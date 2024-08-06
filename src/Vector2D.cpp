#include <cmath>

#include "Vector2D.hpp"


template <typename T>
Vector2D<T>::Vector2D(T x, T y) 
{
    this->x = x;
    this->y = y;
}

template <typename T>
Vector2D<T>::~Vector2D() {}

template struct Vector2D<float>;
template struct Vector2D<int>;


