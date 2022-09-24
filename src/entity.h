#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include "component.h"

using namespace std;

class Entity
{
  public:
    Entity(string name);
    string name;
    vector<Component> components();
    void Update();
    void Render();
    void Initialise();
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
};

#endif
