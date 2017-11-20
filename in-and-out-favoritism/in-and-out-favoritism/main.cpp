#include "Coop_Game.h"
#include "Agent.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N_AGENTS 1000
#define N_STEPS 1000
#define N_TRAIN 1000
#define A_IN 1
#define A_OUT 0.6

int main(){
	int N_GROUPS = 5; 
	int* groups;
	int a1, a2, a3, a4;
	Agent** agents;
	Coop_Game* pris_dilemma = new Coop_Game(1.5, -0.5);
	Coop_Game* stag_hunt = new Coop_Game(0.5, -0.5);
	Coop_Game* snowdrift = new Coop_Game(1.5, 0.5);

	Interaction* interaction = pris_dilemma;

	srand(time(NULL));       	
	groups = (int*) malloc (N_GROUPS * sizeof(int)); 
	agents = (Agent**) malloc( N_AGENTS * sizeof(Agent *));
	
	printf("______INITIALIZAITON_____");

	for(int i = 0; i < N_GROUPS; i++){
		groups[i] = 0;
	}
	
	for(int i = 0; i < N_AGENTS; i++){
		int group = rand() % N_GROUPS;
		agents[i] = new Agent(group);
		groups[group]++;
		printf("GROUP %d\n", agents[i]->set);
		printf("STRATEGY (%f,%f)\n", agents[i]->strategy.first, agents[i]->strategy.second);
		printf("___________________________\n");
	}

	for(int i = 0; i < N_GROUPS; i++){
		printf("GROUP %d: %d\n", i, groups[i]);
	}

	printf("______INITIALIZAITON_____");

	for(int i = 0; i < N_STEPS; i++){
		a1 = rand() % N_AGENTS; 
		for(int i = 0; i < N_TRAIN; i++){
			a2 = rand() % N_AGENTS;
		       	if(a1 == a2)
				continue;
			else{
				if(agents[a1]->set == agents[a2]->set){
					interaction->play(agents[a1],agents[a2]);
					continue;
				}
				if( (((double) rand())/ RAND_MAX ) < A_OUT){
					interaction->play(agents[a1],agents[a2]);
					continue;
				}
			}
		}
		
		a3 = rand() % N_AGENTS; 
		for(int i = 0; i < N_TRAIN; i++){
			a4 = rand() % N_AGENTS;
		       	if(a3 == a4)
				continue;
			else{
				if(agents[a3]->set == agents[a4]->set){
					interaction->play(agents[a3],agents[a4]);
					continue;
				}
				if( (((double) rand())/ RAND_MAX ) < A_OUT){
					interaction->play(agents[a3],agents[a4]);
					continue;
				}
			}
		}

		if( agents[a3]->fitness > agents[a1]->fitness){
			agents[a1]->strategy.first = agents[a3]->strategy.first;
			agents[a1]->strategy.second = agents[a3]->strategy.second;
		}
	}

	for(int i = 0; i < N_AGENTS; i++){
		printf("GROUP %d\n", agents[i]->set);
		printf("STRATEGY (%f,%f)\n", agents[i]->strategy.first, agents[i]->strategy.second);
		printf("NUM_PLAYS %d\n", agents[i]->num_of_plays);
		printf("FITNESS %f\n", agents[i]->fitness);
		printf("___________________________\n");
	}
		
	return 0;
}
