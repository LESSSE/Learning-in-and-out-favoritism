#ifndef COOPGAME_H
#define COOPGAME_H

#include "Interaction.h"

class CoopGame : public Interaction 
{
private:
	double p, r, s, t;

public: 
	CoopGame(double new_t, double new_s);
	virtual ~CoopGame() {};
	float game(Move p1, Move p2);
};

#endif

