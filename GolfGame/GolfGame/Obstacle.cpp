//
//  Obstacle.cpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y, int w, int h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void Obstacle::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, 0xFF); // kolor przeszkody <- tu szary
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Obstacle::getRect() const
{
    return rect;
}
