#ifndef ORGANISM_H
#define ORGANISM_H

#include <memory>

#include "world.h"
#include "genotype.h"
#include "decision.h"

class Organism
{
private:
    OrganismBody body_;
    OrganismCondition condition_;
    const Genotype genotype_;
    const OrganismLogic logic_;
    void do_decision(const Decision* const);
};


class OrganismBody: public WorldObject, public EventObject
{
    void realise(const std::unique_ptr<const Decision>);
};


class OrganismLogic
{
private:
    AbsoluteTime last_decision_time_;

public:
    explicit Logic(const Genotype&);
    const std::unique_ptr<const Decision> make_decision(const OrganismCondition&,
        const tuple<OrganismUnderstoodWorldInformation>&);

};


class OrganismCondition
{
};


class OrganismUnderstoodWorldInformation
{

};

#endif
