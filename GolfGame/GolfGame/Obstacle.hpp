//
//  Obstacle.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Obstacle
{
public:
    Obstacle(int x, int y, int width, int height);
    void render(SDL_Renderer* renderer) const;
    const SDL_Rect& getRect() const;
    
private:
    SDL_Rect rect;
};

#endif /* Obstacle_hpp */
