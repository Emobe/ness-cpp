#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <memory>
#include "component.h"

class Entity
{
  public:
    Entity(std::string name);
    std::string name;
    void Update();
    void Render();
    void Initialise();
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
  private:
    std::vector<std::shared_ptr<Component>> components;
};

#endif
