//
//  Vector2D.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <stdio.h>
#include <cmath>

class Vector2D
{
public:
    float x;
    float y;
    
    Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const
    {
        return Vector2D(x + other.x, y + other.y);
    }
    
    Vector2D& operator+=(const Vector2D& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D operator*(float scalar) const
    {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2D normalize() const
    {
        float len = length();
        if (len > 0.0f)
            return *this * (1.0f / len);
        return Vector2D(0.0f, 0.0f);
    }
};
#endif /* Vector2D_hpp */
