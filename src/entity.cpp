#include <string>
#include "../includes/entity.h"

Entity::Entity(std::string name)
{
  Entity::name = name;
}

void Entity::AddComponent(Component* component){
  components.emplace_back(component);
}
