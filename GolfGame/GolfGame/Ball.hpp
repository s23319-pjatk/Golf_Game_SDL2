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
#include "Obstacle.hpp"

class Ball
{
public:
    Ball(float x, float y, int size);

    void update();
    void render(SDL_Renderer* renderer);
    void applyForce(const Vector2D& force);
    void saveCurrentPosition();
    void resetToLastPosition();
    void handleCollision(const Obstacle& obstacle);  
    void reflectX() {velocity.x = -velocity.x;}
    void reflectY() {velocity.y = -velocity.y;}
    SDL_Rect getRect() const;

private:
    Vector2D position;
    Vector2D velocity;
    Vector2D lastPosition; // zmienna do przechowywania ostatniej pozycji
    int size;

    void applyFriction();
};

#endif /* Ball_hpp */
