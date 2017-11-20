#ifndef INTERACTION_H
#define INTERACTION_H

#include "Agent.h"
#include "Move.h"
class Interaction{
	
public: 
	Interaction();
	virtual ~Interaction() {} ;
	void play(Agent* a1, Agent* a2);
	virtual	float game(Move p1, Move p2) = 0;
};

#endif

