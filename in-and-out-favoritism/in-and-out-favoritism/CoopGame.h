#ifndef COOPGAME_H
#define COOPGAME_H

#include "Interaction.h"

class CoopGame : public Interaction 
{
private:
	float p, r, s, t;

public: 
	CoopGame(float new_t, float new_s);
	virtual ~CoopGame() {};
	float game(Move p1, Move p2);
};

#endif

