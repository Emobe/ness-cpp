#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../includes/game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
  Game* game = new Game("Ness", SCREEN_WIDTH, SCREEN_HEIGHT);
  game->Run();
  return 0;
}
