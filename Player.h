#pragma once
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Player
{
public:

	Player(string name, int accuracy);
	Player();
	~Player();
	int hit;
	int game_wins;
	int set_wins;


private:

	string name;
	int accuracy;
	int score;

public:		

	string getName();
	int getScore();
	void updateScore(int score);
	void setScore(int p_score);

	int ThrowBull();
	int ThrowSingle(int aim);
	int ThrowTreble(int aim);
	int ThrowDouble(int aim);
		
};

