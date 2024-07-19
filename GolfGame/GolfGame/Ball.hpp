//
//  Ball.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Vector2D.hpp"

class Ball
{
public:
    Ball(float x, float y, int size);

    void update();
    void render(SDL_Renderer* renderer);
    void applyForce(const Vector2D& force);
    SDL_Rect getRect() const;

private:
    Vector2D position;
    Vector2D velocity;
    int size;

    void applyFriction();
};

#endif /* Ball_hpp */
