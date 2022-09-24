#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "../includes/SDL_include.h"
#include "../includes/resources.h"
#include "../includes/game.h"
#include <string>
#include <memory>
#include <unordered_map>
#include <utility>
#include <stdexcept>


std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Resources::imageMap;

std::shared_ptr<SDL_Texture> Resources::GetImage(const std::string& file){
  auto map = imageMap.find(file);
  if(map != imageMap.end()){
    return map->second;
  }

  SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
  if(texture == nullptr) {
    throw std::runtime_error("Could not load texture: " + file + ": " + IMG_GetError());
  }

  std::shared_ptr<SDL_Texture> textureSp(texture, [=](SDL_Texture* texture){SDL_DestroyTexture(texture);});
  imageMap.insert(std::make_pair(file, textureSp));
  return textureSp;

}
