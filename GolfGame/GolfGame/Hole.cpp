//
//  Hole.cpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#include "Hole.hpp"

Hole::Hole(int x, int y, int size)
{
    holeRect = { x, y, size, size };
}

void Hole::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // kolor dołka rgba w tym przypadku czarny ;)
    SDL_RenderFillRect(renderer, &holeRect);
}

SDL_Rect Hole::getRect() const
{
    return holeRect;
}
