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

// Klasa reprezentująca przeszkodę
class Obstacle {
protected:
    SDL_Rect rect;

public:
    Obstacle(int x, int y, int width, int height); // Deklaracja konstruktora

    SDL_Rect getRect() const;  // Deklaracja funkcji zwracającej prostokąt

    // Metoda renderująca przeszkodę
    virtual void render(SDL_Renderer* renderer) const;

    virtual ~Obstacle() = default; // Wirtualny destruktor dla poprawnego dziedziczenia
};


#endif /* Obstacle_hpp */
