#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL
#include "SDL_include.h"
#include "component.h"

class Sprite : public Component {
  void Render() override;
};

#endif
