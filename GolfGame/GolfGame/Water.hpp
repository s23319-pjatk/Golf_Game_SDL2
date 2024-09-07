//
//  Water.hpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 06/09/2024.
//

#ifndef Water_hpp
#define Water_hpp

#include "Obstacle.hpp"
#include "SDL2/SDL.h"

// Klasa Water dziedzicząca po Obstacle
class Water : public Obstacle {
public:
    Water(int x, int y, int width, int height)
        : Obstacle(x, y, width, height) {} // Konstruktor przekazuje wartości do Obstacle

    // Metoda renderowania wody (niebieski kolor)
    void render(SDL_Renderer* renderer) const override {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Niebieski kolor
        SDL_Rect rect = getRect();
        SDL_RenderFillRect(renderer, &rect);
    }
};


#endif /* Water_hpp */
