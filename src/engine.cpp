#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "engine.h"
#include "texture.h"

Engine::Engine(std::string title, int width, int height)
{
  Engine::width = width;
  Engine::height = height;
  Engine::title = title;
  Engine::renderer = NULL;
  Engine::testTexture = NULL;

  if(Engine::createWindow())
  {
    Engine::start();
  }
}


bool Engine::createWindow(){
  SDL_Log("Creating window");
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    SDL_Log("SDL could not start. SDL_Error: %s\n", SDL_GetError());
  }
  else 
  {
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        0
        );

    if(window == NULL){
      SDL_Log("Window not created. SDL_Error: %s\n", SDL_GetError());
      return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL)
    {
      SDL_Log("Could not create renderer. SDL Error: %s\n", SDL_GetError());
      return false;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags))
    {
      SDL_Log("Could not load SDL_image. SDL_image Error: %s\n", IMG_GetError());
      return false;
    }

    mainSurface = SDL_GetWindowSurface(window);

    Uint32 green = SDL_MapRGB(mainSurface->format, 4, 106, 56);
    SDL_FillRect(mainSurface, NULL, green);
    SDL_UpdateWindowSurface(window);
  }

  return true;
};

void Engine::start()
{
  running = true;
  Engine::load();
  Engine::loop();
}

void Engine::load()
{
  Texture t = Texture(renderer);
  testTexture->load("face.png");
}

void Engine::close(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Engine::update()
{
}

void Engine::draw()
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 255);
  SDL_RenderClear(renderer);
  //testTexture->render(0, 0);
  SDL_RenderPresent(renderer);
}

void Engine::loop()
{
  while(running)
  {
    while(SDL_PollEvent(&event) != 0)
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
        close();
      }
      update();
      draw();
    }
  }
}
