#include "Agent.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::Play(bool same_group) 
{
	if (same_group) 
	{
		//cooperate
	}
	else 
	{
		//generate random number that will determine if agent cooperates or defects.
	}
}

void Agent::Update_Fitness(float new_value) 
{
	fitness = new_value;
}