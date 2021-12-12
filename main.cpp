//  Written by Anish Gautam (P2657398)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char DisplayMenu(); //shows menu
void MenuOptions(char menuInput); //sorts the input
void MainGameInput();

int PlayerInput();
int CompInput();
void CheckResult(int playerIn, int compIn);
void GameInfo(); //information about the game
void DisplayGameOptions(); //displays the options a user can put in
void InitialiseGame();
void QuitOptions();

bool gameActive = false; //so the game can be replayed
bool goodInput = false; //allows return to menu

char playAgain;


bool results[5][5] = //rock, paper, scis, lzrd, spock - player
{					{true, true, false, false, true}, //rock - comp
					{false, true, true, true, false}, //paper
					{true, false, true, false, true}, //scissors
					{true, false, true, true, false}, //lizard
					{false, true, false, true, true}, }; //spock


int main()
{
	while (goodInput == false) {
		MenuOptions(DisplayMenu());
	}
	while (gameActive == true) {
		//replays when option is selected
		MainGameInput();
	}
	return 0;
}

char DisplayMenu()
{
	// displays the menu

	char menuInput; //allows only single character

	system("CLS");

	cout << "______________________________________" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "|| Rock Paper Scissors Lizard Spock ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "|| [P] Start game                   ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "|| [I] Game info                    ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "|| [Q] Exit game                    ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "||__________________________________||" << endl;
	cout << endl; // formatting

	cout << "Please enter the command you would like to use: ";
	cin >> menuInput;

	return menuInput;

}

void MenuOptions(char menuInput)
{

	switch (menuInput) {
	case 'P':
	case 'p':
		goodInput = true;
		PlayerInput();
		break;
	case 'I':
	case 'i':
		goodInput = true;
		GameInfo();
		break;
	case 'Q':
	case 'q':
		goodInput = true;
		QuitOptions();
		break;
	default:
		cout << "Invalid Input! ";
		system("pause");
		goodInput = false;
		break;
	}
}

void MainGameInput()
{
	CheckResult(CompInput(), PlayerInput());
}

int PlayerInput()
{
	int playerIn = 0;

	InitialiseGame();

	cout << "Choose your move: ";
	cin >> playerIn;

	if (playerIn < 0 || playerIn > 4)
	{
		cout << "Invalid Input! ";
		system("pause");
		PlayerInput();
	}
	
	return playerIn;
}

int CompInput()
{
	int compIn = 0;

	compIn = rand() % 4;

	return compIn;
}

void CheckResult(int playerIn, int compIn)
{
	//prevent ties

	results[5][5] = results[playerIn][compIn];

	if (results[5][5] == true)
	{
		if(playerIn = compIn)
		{
			cout << "Computer has rolled " << compIn << "!" << endl;
			cout << "It's a draw!" << endl;
			cout << "Play again [Y/N]? ";
			cin >> playAgain;
		}
	}
	else if (results[5][5] == false)
	{
		cout << "Computer has rolled " << compIn << "!" << endl;
		cout << "Computer wins!" << endl;
		cout << "Play again [Y/N]? ";
		cin >> playAgain;
	}
	
}

void InitialiseGame()
{
	system("CLS"); // removes the menu
	gameActive = true;
	DisplayGameOptions();
}

void DisplayGameOptions()
{
	// this just shows the player their options, so they know what to input

	cout << "________________________________________________________________________________" << endl;
	cout << "||----------------------------------------------------------------------------||" << endl;
	cout << "|| [0] = Rock || [1] = Paper || [2] = Scissors || [3] = Lizard || [4] = Spock ||" << endl;
	cout << "||----------------------------------------------------------------------------||" << endl;
	cout << "||____________________________________________________________________________||" << endl;
	cout << endl; //formatting

}

void QuitOptions()
{
	goodInput = true;

	cout << "Thank you for playing. ";
	system("pause");
	return;
}

void GameInfo()
{
	goodInput = true;
	system("CLS");

	cout << endl; //formatting
	cout << " Rock Paper Scissors Lizard Spock (RPSLS) is  a variant of" << endl;
	cout << " Rock Paper Scissors that has five choices. Each choice wins against" << endl;
	cout << " two other choices, loses against two other choices, and ties against itself:" << endl;
	cout << " - Rock crushes Lizard and crushes Scissors" << endl;
	cout << " - Paper disproves Spock and covers Rock" << endl;
	cout << " - Scissors cuts Paper and decapitates Lizard" << endl;
	cout << " - Lizard poisons Spock and eats Paper" << endl;
	cout << " - Spock smashes Scissors and vaporises Rock" << endl;
	cout << endl;
	system("pause");

	goodInput = false;

	return;
}
