//
//  Ball.cpp
//  GolfGame
//
//  Created by Marceli Gosztyła on 28/06/2024.
//


#include "Ball.hpp"

Ball::Ball(float x, float y, int size)
    : position(x, y), velocity(0.0f, 0.0f), size(size) {}

void Ball::update()
{
    // Aktualizujemy pozycję na podstawie prędkości
    position += velocity;

    // Dodajemy tarcie, aby spowolnić piłkę
    applyFriction();

    // Zapewniamy, że piłka nie będzie się poruszać poza granicami okna
    if (position.x < 0) {
        position.x = 0;
        velocity.x = -velocity.x; // Odbicie
    }
    if (position.x > 800 - size) {
        position.x = 800 - size;
        velocity.x = -velocity.x; // Odbicie
    }
    if (position.y < 0) {
        position.y = 0;
        velocity.y = -velocity.y; // Odbicie
    }
    if (position.y > 600 - size) {
        position.y = 600 - size;
        velocity.y = -velocity.y; // Odbicie
    }
}

void Ball::render(SDL_Renderer* renderer)
{
    SDL_Rect fillRect = { static_cast<int>(position.x), static_cast<int>(position.y), size, size };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Biały kolor
    SDL_RenderFillRect(renderer, &fillRect);
}

void Ball::applyForce(const Vector2D& force)
{
    velocity += force;
}

SDL_Rect Ball::getRect() const
{
    return { static_cast<int>(position.x), static_cast<int>(position.y), size, size };
}

void Ball::applyFriction()
{
    const float friction = 0.98f; // Współczynnik tarcia
    velocity *= friction;

    // Jeśli prędkość jest bardzo mała, zatrzymujemy piłkę
    if (velocity.length() < 0.1f) {
        velocity = Vector2D(0.0f, 0.0f);
    }
}
