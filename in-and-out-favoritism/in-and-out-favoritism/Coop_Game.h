#ifndef COOP_GAME_H
#define COOP_GAME_H

#include "Interaction.h"

class Coop_Game : public Interaction 
{
private:
	float p, r, s, t;

public: 
	Coop_Game(float new_t, float new_s);
	virtual ~Coop_Game() {};
	float game(Move p1, Move p2);
};

#endif

