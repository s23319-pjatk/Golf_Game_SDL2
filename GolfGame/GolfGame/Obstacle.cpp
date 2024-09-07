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
    SDL_SetRenderDrawColor(renderer, 0x40, 0x40, 0x40, 0xFF); // Kolor przeszkody, tu niebieski
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Obstacle::getRect() const // Typ zwracany nie powinien być referencją, tylko samym typem
{
    return rect;
}
