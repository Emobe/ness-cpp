#include <SDL2/SDL.h>

class Tile
{
  private:
    SDL_Rect rectangle;
    int type;

  public:
    Tile(int x, int y, int type);

    void render();
    int getType();
    SDL_Rect getRect();
}
