#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include <string>
#include "texture.h"

class Engine {

  private:
    SDL_Window* window;
    SDL_Surface* mainSurface;

    std::string title;

    int width;
    int height;

    bool createWindow();
    bool running;
    SDL_Event event;
    SDL_Renderer* renderer;

    Texture* testTexture;
    

  public:
    Engine(std::string title, int width, int height);
    void start();
    void load();
    void loop();
    void close();
    void update();
    void draw();
};

#endif
