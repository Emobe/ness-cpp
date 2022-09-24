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
};
