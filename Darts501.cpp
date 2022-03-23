#include <iostream>
#include <cstdlib>
#include<string>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <time.h>
#include "Player.h"
using namespace std;

int t_score = 0;
int score;
int n = 0;
bool won = 0;
bool turn = 0;
//array to store information about set wins 
int score_set[8] = { 0,0,0,0,0,0,0,0 };



// Create player objects with accuracy 
Player P1("Joe", 80);
Player P2("Sid", 88);



//Creates the statistics of the game
void Statistics()
{
	if (P1.set_wins == 7 && P2.set_wins==0)
	{
		score_set[0]++;
	}
	else if (P1.set_wins == 7 && P2.set_wins == 1)
	{
		score_set[1]++;
	}else if(P1.set_wins == 7 && P2.set_wins == 2)
	{
		score_set[2]++;
	}
	else if (P1.set_wins == 7 && P2.set_wins == 3) 
	{
		score_set[3]++;
	}
	else if (P1.set_wins == 7 && P2.set_wins == 4)
	{
		score_set[4]++;
	}
	else if (P1.set_wins == 7 && P2.set_wins == 5)
	{
		score_set[5]++;
	}
	else if (P1.set_wins == 7 && P2.set_wins == 6)
	{

		score_set[6]++;
	}
	else {
		score_set[7]++;
	};
		

}
//Shows statistics of game
void Show_Stats()
{
	cout << "-------------------------------" << endl;
	cout << "7 : 0 ------" << score_set[0] << "% |" << endl;
	cout << "7 : 1 ------" << score_set[1] << "% |" << endl;
	cout << "7 : 2 ------" << score_set[2] << "% |" << endl;
	cout << "7 : 3 ------" << score_set[3] << "% |" << endl;
	cout << "7 : 4 ------" << score_set[4] << "% |" << endl;
	cout << "7 : 5 ------" << score_set[5] << "% |" << endl;
	cout << "7 : 6 ------" << score_set[6] << "% |" << endl;
	cout << "Other Player Wins: " << score_set[7] << "%" << endl;
}
// Random Number Function
void Randomness()
{
	srand((time(NULL)));
}
/*Resets Players Score*/
void Reset()
{ 
	P1.setScore(501);
	P2.setScore(501);
}  
//Switches Player's turns
void Switch()
{
	if (turn == 0) { turn = 1; }
	else if (turn == 1) { turn = 0; };
		
}
// Play Loop For Player 1 
void Play1() 
{	
	while (n < 3 && won==0)// 3 Throws loop
	{
		if (P1.getScore() == 0)
		{
			P1.game_wins = P1.game_wins + 1;
			won = 1;
		}
		if (P1.getScore() > 70)
		{
			P1.hit = P1.ThrowTreble(20);
		}
		else if (P1.getScore() > 50 && P1.getScore() < 70)
		{
			score = P1.getScore() - 50;
			P1.hit = P1.ThrowSingle(score);
		}
		else if (P1.getScore() == 50)
		{
			P1.hit = P1.ThrowBull();
		}
		else if (P1.getScore() < 50)
		{
			score = P1.getScore();
			if (score % 2 == 0)
			{
				score = score / 2;
			}
			else
			{
				score = (score - 1) / 2;
			}

			if (score > 20)
			{
				score = score - 20;
				P1.hit = P1.ThrowSingle(score);
			}
			else {
				P1.hit = P1.ThrowDouble(score);
			}
		}
		t_score = P1.hit + t_score;
		P1.updateScore(P1.hit);
		n++;
	}
	//Reset if score is invalid (a negative number / can't be hit with a double)
	if (P1.getScore() < 0 || P1.getScore() == 1) 
	{
		P1.updateScore(t_score * (-1));
		t_score = 0;
	}
	else {
		t_score = 0;
	}
	n = 0;
	
}
// Play Loop For Player 2 
void Play2()
{
	while (n < 3 && won == 0){

		if (P2.getScore() == 0)
		{
			
			P2.game_wins = P2.game_wins + 1;
			won = 1;
		}
		if (P2.getScore() > 70)
		{
			P2.hit = P2.ThrowTreble(20);

		}
		else if (P2.getScore() > 50 && P2.getScore() < 70)
		{
			score = P2.getScore() - 50;
			P2.hit = P2.ThrowSingle(score);
		}
		else if (P2.getScore() == 50)
		{
			P2.hit = P2.ThrowBull();
		}
		else if (P2.getScore() < 50)
		{
			score = P2.getScore();
			if (score % 2 == 0)
			{
				score = score / 2;
			}
			else
			{
				score = (score - 1) / 2;
			}

			if (score > 20)
			{
				score = score - 20;
				P1.hit = P2.ThrowSingle(score);
			}
			else {
				P2.hit = P2.ThrowDouble(score);
			}
		}
		t_score = P1.hit + t_score;
		P2.updateScore(P2.hit);
		n++;
	}
	//Resets if score is invalid (a negative number / can't be hit with a double)
	if (P2.getScore() < 0 || P2.getScore() == 1)
	{
		
		P2.updateScore(t_score * (-1));
		t_score = 0;
	}
	else {
		t_score = 0;
	}
	n = 0;
}



int main() {
	Randomness();
	// Main game loop 
	for (size_t i = 0; i < 100; i++)
	{	// Play until someone wins the game 
		while (P1.set_wins < 7 && P2.set_wins < 7) 
		{
			//Play the best of 5 games 
			while (P1.game_wins < 3 && P2.game_wins < 3) 
			{
				if (turn == 0) 
				{
					while (won == 0)
					{

						Play1();
						Play2();
					}
				}
				else if (turn == 1)
				{
					while (won == 0)
					{

						Play2();
						Play1();
					}
				}
				//Switch Places
				Switch();
				//Reset Score
				Reset();
				won = 0;
			}
			//Play until one of the players game wins reach 3 (first to 3)
			if (P1.game_wins == 3)
			{
				P1.set_wins = P1.set_wins + 1;
			}
			else if (P2.game_wins == 3)
			{
				P2.set_wins = P2.set_wins + 1;
			}

			P1.game_wins = 0; P2.game_wins = 0;
		}
		//Store set information inside array 
		Statistics();
		cout << "Set score is: " << P1.set_wins << " : " << P2.set_wins << endl;
		//Reset set wins 
		P1.set_wins = 0; P2.set_wins = 0;

	}
	//Show percentage after certain ammount of games
	Show_Stats();

	system("Pause");

	
	
}


