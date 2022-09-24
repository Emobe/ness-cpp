#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
#include <unordered_map>

#define ESCAPE_KEY SDLK_ESCAPE


class InputManager {
  public:
    InputManager();
    ~InputManager();
    static InputManager& GetInstance();

    void Update();

    int GetMouseX() const;
    int GetMouseY() const;

    bool KeyPress(int key);
    bool KeyUp(int key);
    bool KeyDown(int key);

    bool MousePress(int button) const;
    bool MouseUp(int button) const;
    bool MouseDown(int button) const;

  private:
    static InputManager instance;
    bool quit;

    bool mouseState[6];
    int mouseUpdate[6];

    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, int> keyUpdate;

    int updateCounter;
    int mouseX;
    int mouseY;
};

#endif
