#include "CoopGame.h"
#include "Agent.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>

//NUMBERS
#define N_AGENTS 1000
#define N_STEPS 100000
#define N_TRAIN 10000

//PROBABILITIES
#define A_IN 1
#define A_OUT 0.6

#define BETA 1
#define DEV 0.01 


float func(float x, float y){
	float diff = x - y;
	return 1 / (1 + std::exp(- BETA * diff));
}

float dev(){
	float r;
	r = ((double) rand() / (RAND_MAX));
	r -= 0.5;
	r *= DEV;
	return r;
}

void getFitness(Interaction* interaction, Agent** agents, int agent){
	int a;
	for(int i = 0; i < N_TRAIN; i++){
		a = rand() % N_AGENTS;
		if(a == agent)
			continue;
		else{
			if(agents[a]->set == agents[agent]->set){
				interaction->play(agents[agent],agents[a]);
				continue;
			}	
			if( (((double) rand()) / (RAND_MAX)) < A_OUT){
				interaction->play(agents[agent],agents[a]);
				continue;
			}
		}
	}	
}

int main(){
	int N_GROUPS = 20; 
	int* groups;
	int a1, a2;
	Agent** agents;
	CoopGame* pris_dilemma = new CoopGame(1.5, -0.5);
	//CoopGame* stag_hunt = new CoopGame(0.5, -0.5);
	//CoopGame* snowdrift = new CoopGame(1.5, 0.5);

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
		/*
		 printf("GROUP %d\n", agents[i]->set);
		printf("STRATEGY (%f,%f)\n", agents[i]->strategy.first, agents[i]->strategy.second);
		printf("___________________________\n");
		*/
	}

	for(int i = 0; i < N_GROUPS; i++){
		printf("GROUP %d: %d\n", i, groups[i]);
	}

	printf("______TRAIN_____");

	for(int i = 0; i < N_STEPS; i++){
		int r;
		a1 = rand() % N_AGENTS;
		getFitness(interaction, agents,a1);
		a2 = rand() % N_AGENTS; 
		getFitness(interaction, agents,a2);
		r = ((double) rand() / (RAND_MAX));	
		if( r <= func(agents[a2]->fitness,agents[a1]->fitness)){
			agents[a1]->strategy.first = agents[a2]->strategy.first + dev();
			agents[a1]->strategy.second = agents[a2]->strategy.second + dev(); 
			printf("STRATEGY CHANGE (%f,%f) (%f,%f)\n",agents[a1]->strategy.first, agents[a1]->strategy.second + dev(), agents[a2]->strategy.first, agents[a2]->strategy.second);	
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
