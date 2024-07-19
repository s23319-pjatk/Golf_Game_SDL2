#include <SDL2/SDL.h>
#include <iostream>
#include "Ball.hpp"
#include "GolfCourse.hpp"
#include "Hole.hpp"
#include "Obstacle.hpp"
#include "Vector2D.hpp"
#include "Level.hpp"

// Rozmiary okna
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Rozmiar piłki
const int BALL_SIZE = 20;

// Rozmiar dołka
const int HOLE_SIZE = 30;

// Funkcja do sprawdzania kolizji dwóch prostokątów
bool checkCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

    int leftB = b.x;
    int rightB = b.x + b.w;
    int topB = b.y;
    int bottomB = b.y + b.h;

    return !(bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB);
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("2D Golf Game",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    Ball ball(SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2, BALL_SIZE);
    GolfCourse course(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Tworzenie poziomów
    std::vector<Level> levels;
    levels.emplace_back(Hole(SCREEN_WIDTH - HOLE_SIZE - 50, SCREEN_HEIGHT / 2 - HOLE_SIZE / 2, HOLE_SIZE),
                        std::vector<Obstacle>{ Obstacle(200, 200, 100, 20), Obstacle(100, 300, 20, 100) });
    levels.emplace_back(Hole(100, 100, HOLE_SIZE),
                        std::vector<Obstacle>{ Obstacle(300, 200, 150, 20), Obstacle(500, 350, 20, 150) });

    int currentLevel = 0;
    int strokes = 0;

    bool quit = false;
    SDL_Event e;

    // Zmienne do obsługi myszy
    bool mousePressed = false;
    SDL_Point mouseStartPos;
    SDL_Point mouseCurrentPos;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mousePressed = true;
                    mouseStartPos = { e.button.x, e.button.y };
                }
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mousePressed = false;
                    // Oblicz wektor siły
                    Vector2D force(static_cast<float>(mouseStartPos.x - mouseCurrentPos.x),
                                   static_cast<float>(mouseStartPos.y - mouseCurrentPos.y));
                    
                    // Normalizacja i skalowanie siły
                    float length = force.length();
                    if (length > 0.0f) {
                        force = force.normalize() * 5.0f; // Ustaw siłę na 5, skalowanie siły
                    }

                    ball.applyForce(force);
                    strokes++;
                }
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                if (mousePressed)
                {
                    mouseCurrentPos = { e.motion.x, e.motion.y };
                }
            }
        }

        ball.update();

        const auto& currentHole = levels[currentLevel].getHole();
        const auto& obstacles = levels[currentLevel].getObstacles();

        bool collision = false;
        for (const auto& obstacle : obstacles)
        {
            if (checkCollision(ball.getRect(), obstacle.getRect()))
            {
                collision = true;
                break;
            }
        }

        if (collision)
        {
            ball = Ball(SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2, BALL_SIZE);
        }

        if (checkCollision(ball.getRect(), currentHole.getRect()))
        {
            std::cout << "Level " << currentLevel + 1 << " completed in " << strokes << " strokes!" << std::endl;
            currentLevel++;
            if (currentLevel >= levels.size())
            {
                std::cout << "You completed all levels!" << std::endl;
                quit = true;
            }
            else
            {
                ball = Ball(SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2, BALL_SIZE);
                strokes = 0;
            }
        }

        // Czyszczenie ekranu
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Czarny kolor
        SDL_RenderClear(renderer);

        course.render(renderer);
        levels[currentLevel].render(renderer);
        ball.render(renderer);

        // Rysowanie linii kierunku strzału
        if (mousePressed)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Czerwona linia
            SDL_RenderDrawLine(renderer, mouseStartPos.x, mouseStartPos.y, mouseCurrentPos.x, mouseCurrentPos.y);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
