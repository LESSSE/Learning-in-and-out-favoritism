#ifndef AGENT_H
#define AGENT_H

#include <stdlib.h>
#include <time.h>
#include "Move.h"

class Agent
{
public:
	int set;
	
	Agent();
	virtual ~Agent() {};
	Move play(bool same_group);
	void update_fitness(float new_value);
private:
	//Strategy strategy;
	float fitness;
	int num_of_plays;
};
#endif
