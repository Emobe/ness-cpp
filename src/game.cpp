#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "../includes/SDL_include.h"
#include "../includes/game.h"
#include <string>
#include <stdexcept>

Game* Game::instance = nullptr;

Game::Game(const std::string& title, int width, int height) {
  if(instance == nullptr){
    instance = this;
  }else {
    throw std::logic_error("Game instance already exists");
  }

  int sdl_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;
  if(SDL_Init(sdl_flags) != 0) {
    throw std::runtime_error("Failed to initialise SDL");
  }

  int img_flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
  if(IMG_Init(img_flags) != img_flags) {
    throw std::runtime_error("Failed to initialise SDL_Image");
  }

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if(window == nullptr) {
    throw std::runtime_error("Failed to create a window");
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if(renderer == nullptr){
    throw std::runtime_error("Failed to create a 2D renderer");
  }
}

void Game::Run(){
  SDL_RenderPresent(renderer);
  SDL_Delay(33);
}

Game::~Game() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}
