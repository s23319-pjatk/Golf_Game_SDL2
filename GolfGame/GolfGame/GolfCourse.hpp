//
//  GolfCourse.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef GolfCourse_hpp
#define GolfCourse_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class GolfCourse
{
public:
    GolfCourse(int width, int height);
    void render(SDL_Renderer* renderer);
    
private:
    int width;
    int height;

};

#endif /* GolfCourse_hpp */
