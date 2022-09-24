#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <fstream>
#include "texture.h"


Texture::Texture(SDL_Renderer* renderer)
{
  texture = NULL;
  width = 0;
  height = 0;
  renderer = renderer;
}

Texture::~Texture()
{
}

int Texture::getWidth()
{
  return width;
}

int Texture::getHeight()
{
  return height;
}

bool Texture::load(std::string path)
{
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());

  if(renderer == NULL)
  {
    SDL_Log("No renderer for texture");
    return false;
  }

  if(loadedSurface == NULL)
  {
    SDL_Log("Unable to load texture: %s", path.c_str());
    SDL_Log("%s", IMG_GetError());
  }
  else
  {
    SDL_Log("Image loaded");
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    //if(newTexture == nullptr)
    //{
    //  SDL_Log("Unable to create texture: %s\n", path.c_str(), IMG_GetError());
    //}
    //else
    //{
    //  width = loadedSurface->w;
    //  height = loadedSurface->h;
    //}

    //SDL_FreeSurface(loadedSurface);
  }
  texture = newTexture;
  return texture != nullptr;
};

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
  SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setAlpha(Uint8 alpha)
{
  SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
  SDL_Rect renderRect = {x, y, width, height };
  if(clip != NULL)
  {
    renderRect.w = clip->w;
    renderRect.h = clip->h;
  }

  SDL_RenderCopyEx(renderer, texture, clip, &renderRect, angle, center, flip);
}
