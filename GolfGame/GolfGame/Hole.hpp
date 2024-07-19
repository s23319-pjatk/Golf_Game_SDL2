//
//  Hole.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef Hole_hpp
#define Hole_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Hole
{
public:
    Hole(int x, int y, int size);
    void render(SDL_Renderer* renderer) const;
    SDL_Rect getRect() const;
    
private:
    SDL_Rect holeRect;
};

#endif /* Hole_hpp */
