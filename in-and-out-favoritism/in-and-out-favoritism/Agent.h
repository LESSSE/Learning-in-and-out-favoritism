#ifndef AGENT_H
#define AGENT_H

#include <stdlib.h>
#include "Move.h"
#include "Group.h"
#include "Strategy.h"

class Agent
{
public:
	Group set;
	Strategy strategy;
	float fitness;
	int num_of_plays;
	
	Agent(Group g);
	virtual ~Agent() {};
	Move play(bool same_group);
	void update_fitness(float new_value);

};
#endif
