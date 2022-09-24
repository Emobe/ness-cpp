#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>
#include <string>

class Texture
{
  public:

    Texture(SDL_Renderer* renderer);

    ~Texture();
    bool load(std::string path);

    void setBlendMode(SDL_BlendMode blend);

    void setAlpha(Uint8 alpha);
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    void render(
        int x,
        int y,
        SDL_Rect* clip = NULL,
        double angle = 0.0,
        SDL_Point* center = NULL,
        SDL_RendererFlip flip = SDL_FLIP_NONE
        );

    int getWidth();
    int getHeight();

  private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};

#endif
