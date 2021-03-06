#ifndef OBJECTS_H_
#define OBJECTS_H_

class WorldObject;
class EventObject;
class World;

#include "intersection.h"
#include "simulation_clock.h"
#include "view/viewmodel.h"

class Object
{
public:
  virtual ~Object();
};

class EventObject : public virtual Object
{
public:
  virtual ~EventObject();
  virtual const AbsoluteTime get_next_event_time() = 0;
  virtual void update(const AbsoluteTime&) = 0;
};


class WorldObject : public virtual Object
{
protected:
  World* const world_;

public:
  WorldObject(World* const);
  virtual ~WorldObject();
  virtual WorldObjectViewCollection get_view(const Coordinates&, const UnitVector&) = 0;
  virtual std::shared_ptr<Shape> get_shape(const Coordinates&, const UnitVector&) = 0;
};


class WorldPlane : public WorldObject
{
private:
  Distance distance_;

public:
  WorldPlane(World* const, const Distance&);
  virtual WorldObjectViewCollection get_view(const Coordinates&, const UnitVector&);
  virtual std::shared_ptr<Shape> get_shape(const Coordinates&, const UnitVector&);
  const Coordinates get_random_position() const;
};

#endif /* OBJECTS_H_ */
