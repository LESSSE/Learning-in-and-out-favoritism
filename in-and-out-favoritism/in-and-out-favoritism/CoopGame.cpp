#include "CoopGame.h"

CoopGame::CoopGame(double new_t, double new_s){
	t = new_t;
	s = new_s;
	r = 1;
	p = 0;
}

float CoopGame::game(Move m1, Move m2){
	if( m1 > 0 ){ // first cooperate
		return (m2 > 0) ? r : s; 
	}	
	else{ // first defect
		return (m2 > 0) ? t : p;
	}
}	
