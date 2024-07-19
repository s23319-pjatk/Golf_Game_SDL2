//
//  Level.cpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//

#include "Level.hpp"

Level::Level(const Hole& hole, const std::vector<Obstacle>& obstacles)
    : hole(hole), obstacles(obstacles) {}

void Level::render(SDL_Renderer* renderer) const
{
    hole.render(renderer);
    for (const auto& obstacle : obstacles)
    {
        obstacle.render(renderer);
    }
}

const Hole& Level::getHole() const
{
    return hole;
}

const std::vector<Obstacle>& Level::getObstacles() const
{
    return obstacles;
}
