//
//  Level.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#ifndef Level_hpp
#define Level_hpp

#include <stdio.h>
#include <vector>
#include "Hole.hpp"
#include "Obstacle.hpp"

class Level
{
public:
    Level(const Hole& hole, const std::vector<Obstacle>& obstacles);
    void render(SDL_Renderer* renderer) const;
    const Hole& getHole() const;
    const std::vector<Obstacle>& getObstacles() const;
    
private:
    Hole hole;
    std::vector<Obstacle> obstacles;
};

#endif /* Level_hpp */
