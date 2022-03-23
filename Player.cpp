#include "Player.h"
using namespace std;

Player::Player(string p_name, int p_accuracy) 
	{
		name = p_name;
		accuracy = p_accuracy;
		score = 501;
		game_wins = 0;
		set_wins = 0;
	}
Player::Player()
	{
		score =  501;
	}
Player::~Player()
{
}


string Player::getName() 
	{
		return name;
	}
int Player::getScore() 
	{
	return score;
	}
void Player::setScore(int p_score)
{
	score = p_score;
}
void Player::updateScore(int p_score)
{
	score = score - p_score;
}

int Player::ThrowBull() 
	{ 
		int random = rand() % 100;

		if (random<(accuracy - 20))
		{
			return 50;
		}
		else if (random<85)
		{
			return 25;
		}
		else
		{
			return 1 + rand() % 20;
		}

	}
int Player::ThrowSingle(int p_aim)
	{
		//Stores the values to the left or to the right of aim_for
		int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
		{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };

		int c = 1 + rand() % 100;

		if (p_aim == 25)
		{
		if (c <= accuracy)
		{
			return 25;
			
		
		}
		
			else
			{
				int g = rand() % 3;
				if (g == 0 || g == 1)
				{
					return 50;
				}
				else if (g == 2)
				{
					return (1 + rand() % 20);
				}
			}
		}
		else
			{
				int g = (rand() % 5);
				if (c < accuracy) { score = score - p_aim; return p_aim; }
				else if (g == 0 || g == 1) { score = score - bd[0][p_aim]; return bd[0][p_aim]; } //40% chance to hit left value
				else if (g == 2 || g == 3) { score = score - bd[1][p_aim]; return bd[1][p_aim];}//40% chance to hit right value
				else if (g == 4) { score = score - (1 + rand() % 20); return (1 + rand() % 20); }       //20% chance to hit random value
	
		}

	}
int Player::ThrowTreble(int p_aim) 
{
	int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
	{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };

	int r = rand() % 100;

	if (r<accuracy)
	{
		return 3 * p_aim;
	} //treble hit

	else if (r<90)
	{
		return p_aim;
	} //single hit

	else if (r<93)
	{
		return 3 * bd[0][p_aim];
	} //treble of left hand score hit

	else if (r<96)
	{
		return 3 * bd[1][p_aim];
	}//treble of right hand score hit

	else if (r<98)
	{
		return bd[0][p_aim];
	}//single of left hand score hit

	else
	{
		return bd[1][p_aim];
	}//single of left hand score hit

}
int Player::ThrowDouble(int p_aim) 
{
	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
	{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };
	int r = rand() % 100;

	if (r<80)
	{
		return 2 * p_aim;
	}
	else if (r<85)
	{
		return 0;
	}
	else if (r<90)
	{
		return p_aim;
	}
	else if (r<93)
	{
		return 2 * bd[0][p_aim];
	}
	else if (r<96)
	{
		return 2 * bd[1][p_aim];
	}
	else if (r<98)
	{
		return bd[0][p_aim];
	}
	else
	{
		return bd[1][p_aim];
	}
}