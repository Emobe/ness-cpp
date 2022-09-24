#ifndef GAME_H
#define GAME_H


#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

class Game {
  public:
    ~Game();

    SDL_Renderer* GetRenderer();
    static Game& GetInstance();
    Game(const std::string& title, int width, int height);
    void Run();

  private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    bool running;
};

#endif
