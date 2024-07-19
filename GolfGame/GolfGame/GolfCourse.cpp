//
//  GolfCourse.cpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#include "GolfCourse.hpp"

GolfCourse::GolfCourse(int width, int height)
: width(width), height(height)
{
}

void GolfCourse::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x00, 0xFF); //kolor tla w tym przypadku zielony
    SDL_RenderClear(renderer);
}
