#include "CoopGame.h"
#include "Agent.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

//NUMBERS
#define N_AGENTS 1000
#define N_STEPS 10000
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
			if((agents[a]->set == agents[agent]->set) && (((double) rand())/ (RAND_MAX) <= A_IN)){
				interaction->play(agents[agent],agents[a]);
				continue;
			}	
			if( (((double) rand()) / (RAND_MAX)) <= A_OUT){
				interaction->play(agents[agent],agents[a]);
				continue;
			}
		}
	}	
}

void show_usage(std::string name){
	std::cerr << "Usage: " << name << "[-h|-g|-t] tempetation_to_defect suckers_payoff" << std::endl; 
	std::cerr << "  Options:" << std::endl;
	std::cerr << "\t-h\t\tShow this help message" << std::endl; 
	std::cerr << "\t-g\t\tNumber of groups" << std::endl;
       	std::cerr << "\t-t\t\tType of output:\n" << "\t\td\t\t distribution\n" << "\t\tg\t\tpachorialism global evolution\n" << "\t\tl\t\tparochialism group evolution\n" << std::endl;  	
}


float average_parochialism(Agent** agents, int size){
	float par;
	for(int i = 0; i < size; i++){
		par = (par * i + agents[i]->strategy.first/agents[i]->strategy.second)/(i+1);
	}
	return par;
}

float average_group_parochialism(Agent** agents, int size, int group){
	float par;
	int n=0;
	for(int i = 0; i < size; i++){
		if(agents[i]->set == group){
			par = (par * n + agents[i]->strategy.first/agents[i]->strategy.second)/(n+1);
			n++;
		}
	}
	return par;
}


int main(int argc, char* argv[]){
	int N_GROUPS = 20; 
	int* groups;
	int a1, a2;
	char out_type = 'd';
	Agent** agents;
	double s, t;
	//CoopGame* pris_dilemma = new CoopGame(1.2, -0.2);
	//CoopGame* stag_hunt = new CoopGame(0.5, -0.5);
	//CoopGame* snowdrift = new CoopGame(1.5, 0.5);

	Interaction* interaction;

	if(argc < 3){
		show_usage(argv[0]);
		return 1;
	}

	s = atof(argv[argc-2]);
	t = atof(argv[argc-1]);
	interaction = new CoopGame(s,t);

	std::cerr << s <<" "<< t << std::endl;

	for(int i = 1; i < argc-2; i++){
		std::string arg = argv[i];
		if ((arg == "-h")){
			show_usage(argv[0]);
			return 0;
		}
		else if ((arg == "-g")){
			N_GROUPS = atoi(argv[++i]);
		}
		else if ((arg == "-t")){
			out_type = argv[++i][0];
		}
	}

	srand(time(NULL));       	
	groups = (int*) malloc (N_GROUPS * sizeof(int)); 
	agents = (Agent**) malloc( N_AGENTS * sizeof(Agent *));
	
	std::cerr << "______INITIALIZAITON_____" << std::endl;

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
		std::cerr << "GROUP " <<  i << ":\t"<< groups[i] << std::endl;
	}

	std::cerr << "______TRAIN_____" << std::endl;
	
	for(int i = 0; i < N_STEPS; i++){
		int r;
		a1 = rand() % N_AGENTS;
		getFitness(interaction, agents,a1);
		a2 = rand() % N_AGENTS; 
		getFitness(interaction, agents,a2);
		
		r = ((double) rand() / (RAND_MAX));	
		
		//Reinforcement Learning
		if( r <= func(agents[a2]->fitness,agents[a1]->fitness)){
			agents[a1]->strategy.first = agents[a2]->strategy.first + dev();
			agents[a1]->strategy.second = agents[a2]->strategy.second + dev(); 
			//("STRATEGY CHANGE (%f,%f) (%f,%f)\n",agents[a1]->strategy.first, agents[a1]->strategy.second + dev(), agents[a2]->strategy.first, agents[a2]->strategy.second);
			if(out_type == 'g'){
				std::cout << i << "\t" << average_parochialism(agents,N_AGENTS) << std::endl;
			}
			else if(out_type == 'l'){
				for(int j = 0; j < N_GROUPS; j++){
					std::cout << i << "\t" << j << "\t" << average_group_parochialism(agents,N_AGENTS,j) << std::endl;
				}
			}	
		}
	}

	if(out_type == 'd'){
			for(int i = 0; i < N_AGENTS; i++){
				std::cout <<  agents[i]->strategy.first << "\t" << agents[i]->strategy.second << std::endl;
		}
	}
	return 0;
}
