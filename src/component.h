#ifndef COMPONENT_H
#define COMPONENT_H
class Component
{
  private:
    bool enabled;
  public:
    Component();
    virtual ~Component();
    virtual bool isEnabled();
    virtual void update();
    virtual void Render();
    virtual void initialise();
    void enable();
    void disable();
};

#endif
