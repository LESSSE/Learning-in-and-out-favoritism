#include "Agent.h"

Agent::Agent(Group g) {
	strategy.first = ((double) rand() / (RAND_MAX));
	strategy.second = ((double) rand() / (RAND_MAX));
	set = g;
	num_of_plays = 0;
	fitness = 0;
}

Move Agent::play(bool same_group) 
{
	double r;
	if (same_group){
		r = ((double) rand() / (RAND_MAX));	
		return ( r <= strategy.first ) ? -1 : 1;//Strategy first number
	}
	else {
		r = ((double) rand() / (RAND_MAX));	
		return ( r <= strategy.second ) ? -1 : 1; //Strategy second number}	
	}
}

void Agent::update_fitness(float new_value) 
{
	double m;
	m = fitness * num_of_plays;
	m += new_value;
	num_of_plays++;
	fitness = m / num_of_plays;
}
