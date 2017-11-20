#include "Coop_Game.h"

Coop_Game::Coop_Game(float new_t, float new_s){
	t = new_t;
	s = new_s;
	r = 1;
	p = 0;
}

float Coop_Game::game(Move m1, Move m2){
	if( m1 > 0 ){ // first cooperate
		return (m2 > 0) ? r : s; 
	}	
	else{ // first defect
		return (m2 > 0) ? t : p;
	}
}	
