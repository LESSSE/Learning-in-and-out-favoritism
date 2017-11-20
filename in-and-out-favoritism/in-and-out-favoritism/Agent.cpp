#include "Agent.h"

Agent::Agent() {
	srand(time(NULL));
}

Move Agent::play(bool same_group) 
{
	double r;
	if (same_group){
		r = ((double) rand() / (RAND_MAX));	
		return ( r <= 0.6 ) ? -1 : 1;//Strategy first number
	}
	else {
		r = ((double) rand() / (RAND_MAX));	
		return ( r <= 0.1 ) ? -1 : 1; //Strategy second number}	
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
