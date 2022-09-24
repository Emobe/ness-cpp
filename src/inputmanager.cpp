#define INCLUDE_SDL
#include "../includes/SDL_include.h"
#include "../includes/inputmanager.h"

InputManager InputManager::instance;

InputManager& InputManager::GetInstance(){
  return instance;
}

InputManager::InputManager() : updateCounter(0) {
  mouseX = 0;
  mouseY = 0;
  ::memset(mouseState, 0, sizeof(bool)*6);
  ::memset(mouseState, 0, sizeof(int)*6);
}

InputManager::~InputManager() {}

void InputManager::Update(){
  SDL_Event event;
  updateCounter += 1;

  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      quit = true;
    } else if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {

      mouseState[event.button.button] = event.type == SDL_MOUSEBUTTONDOWN;
      mouseUpdate[event.button.button] = updateCounter;

    } else if(!event.key.repeat && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)) {

      keyState[event.key.keysym.sym] = event.type == SDL_KEYDOWN;
      keyUpdate[event.key.keysym.sym] = updateCounter;

    }
  }
}

bool InputManager::KeyPress(int key) {
  return keyState[key] && (keyUpdate[key] == updateCounter);
}
bool InputManager::KeyUp(int key) {
  return !keyState[key] && (keyUpdate[key] == updateCounter);
}

bool InputManager::KeyDown(int key){
  return keyState[key];
}


bool InputManager::MousePress(int button) const {
    return mouseState[button] && (mouseUpdate[button] == updateCounter);
}

bool InputManager::MouseUp(int button) const {
    return !mouseState[button] && (mouseUpdate[button] == updateCounter);
}

bool InputManager::MouseDown(int button) const {
    return mouseState[button];
}

int InputManager::GetMouseX() const {
  return mouseX;
}
int InputManager::GetMouseY() const {
  return mouseY;
}





