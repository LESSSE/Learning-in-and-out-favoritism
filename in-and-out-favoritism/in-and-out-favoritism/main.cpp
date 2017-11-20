#include "Coop_Game.h"
#include "Agent.h"
#include <stdio.h>

int main(){
	Coop_Game* pris_dilemma = new Coop_Game(1.5, -0.5);
	Coop_Game* stag_hunt = new Coop_Game(0.5, -0.5);
	Coop_Game* snowdrift = new Coop_Game(1.5, 0.5);
	
	Agent* a1 = new Agent();
	Agent* a2 = new Agent();

	printf("PrisDilemma: %f\n", pris_dilemma->game(1,1));
	printf("PrisDilemma: %f\n", pris_dilemma->game(-1,1));
	printf("PrisDilemma: %f\n", pris_dilemma->game(1,-1));
	printf("PrisDilemma: %f\n", pris_dilemma->game(-1,-1));
	
	printf("SH: %f\n", stag_hunt->game(1,1));
	printf("SH: %f\n", stag_hunt->game(-1,1));
	printf("SH: %f\n", stag_hunt->game(1,-1));
	printf("SH: %f\n", stag_hunt->game(-1,-1));

	return 0;
}
