////////////////////////////////////////////////////////////////////////
// OOP Tutorial 7: Simple C++ OO program to simulate a simple Dice Game (single file)
////////////////////////////////////////////////////////////////////////

//--------include libraries
#include <ctime>	
#include <iostream>	
#include <string>	
#include "Dice.h"
#include "Player.h"

using namespace std;

//--------RandomNumberGenerator class


//--------end of RandomNumberGenerator class

//--------Dice class

//--------end of Dice class

//--------Score class

//--------end of Score class

//--------Player class


//--------end of Player class

//--------Game class
class Game {
public:
	explicit Game(Player* pplayer);
	void displayData() const;
	void run();
private:
	Player* p_player_;
	Dice firstDice_, secondDice_;
	int numberOfGoes_;
	void rollDices();
};
Game::Game(Player* pplayer) 
: p_player_(pplayer), firstDice_(), secondDice_(), numberOfGoes_(0)
{
	p_player_->readInName();
	numberOfGoes_ = p_player_->readInNumberOfGoes();
}
void Game::displayData() const {
	cout << "\nPlayer is: " << p_player_->getName();
	cout << "\nScore is: " << p_player_->getScoreAmount() << endl;
}
void Game::run() {
	for (int i(1); i <= numberOfGoes_; ++i)
	{
		rollDices();
		const int face1(firstDice_.getFace());
		const int face2(secondDice_.getFace());
		cout << "\nIn try no: " << i << " \tdice values are: "
			<< face1 << " and " << face2;
		if ((face1 == face2) && (face1 == 6))
			p_player_->updateScore(p_player_->getScoreAmount());
		else
			if (face1 == face2)
				p_player_->updateScore(face1);
		//check current score
		cout << "\tThe current score is: " << p_player_->getScoreAmount();
	}
}
void Game::rollDices() {
	firstDice_.roll();
	secondDice_.roll();
}
//--------end of Game class

//---------------------------------------------------------------------------
//with two dices
int main()
{
	Player player;
	Game twoDiceGame(&player);
	cout << "\n________________________";
	cout << "\nGame starting...";
	twoDiceGame.displayData();
	cout << "\n________________________";
	twoDiceGame.run();
	cout << "\n________________________";
	cout << "\nGame ended...";
	twoDiceGame.displayData();
	cout << "\n________________________\n";

	system("pause");
	return 0;
}

