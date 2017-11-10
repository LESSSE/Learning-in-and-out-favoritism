#pragma once
class Agent
{
public:
	Agent();
	~Agent();
	void Play(bool same_group);
	void Update_Fitness(float new_value);
private:
	//Strategy strategy;
	int set;
	float fitness;
	int num_of_plays;
};