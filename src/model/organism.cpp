#include "model/organism.h"


Organism::Organism(World * const world, const AbsoluteTime& time)
  : WorldObject(world), last_decision_time_(time),
    genotype_(Genotype()), logic_(OrganismLogic())
{

}

Organism::~Organism()
{

}

void Organism::update(AbsoluteTime const &time)
{
  if(time >= last_decision_time_ + TimeDifference::seconds(1))
  {
    logic_.make_decision();
    last_decision_time_ = time;
  }
}

WorldObjectView* Organism::get_view(const Coordinates& coordinates,
  const UnitVector& direction)
{
  return new TriangleWorldObjectView(coordinates, direction);
}

const AbsoluteTime Organism::get_next_event_time()
{
  return last_decision_time_ + TimeDifference::seconds(1);
}
