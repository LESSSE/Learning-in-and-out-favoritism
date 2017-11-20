#include "Interaction.h"

Interaction::Interaction(){
}

void Interaction::play(Agent* a1, Agent* a2){
	float n_value1, n_value2;
	bool same_set = (a1->set == a2->set);
	Move p1 = a1->play(same_set);
	Move p2 = a2->play(same_set);
	
	n_value1 = game(p1,p2);
	n_value2 = game(p2,p1);

	a1->update_fitness(n_value1);
	a2->update_fitness(n_value2);
}	
