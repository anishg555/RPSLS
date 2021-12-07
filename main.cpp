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
void HowToPlay(); //instructions
void DisplayGameOptions(); //displays the options a user can put in
void InitialiseGame();
void QuitOptions();

bool gameActive = false; //so the game can be replayed
bool goodInput = false;

int selectInput = 0;

bool results[5][5] = //rock, paper, scis, lzrd, spock - player
{						{true, true, false, false, true}, //rock - comp
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
	cout << "|| [H] How to play                  ||" << endl;
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
	case 'H':
	case 'h':
		goodInput = true;
		HowToPlay();
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
	cin >> selectInput;

	switch (selectInput) {
	case 'R':
	case 'r':
		playerIn = 0;
	case 'P':
	case 'p':
		playerIn = 1;
	case 'S':
	case 's':
		playerIn = 2;
	case 'L':
	case 'l':
		playerIn = 3;
	case 'K':
	case 'k':
		playerIn = 4;
	default:
		cout << "Invalid input! ";
		system("pause");
		system("CLS");
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

	if (playerIn == compIn)
	{
		cout << "Draw!" << endl;
		cout << "Play again [Y/N]? ";

	}
	else
	{
		results[5][5] = results[playerIn][compIn];

		if (results[5][5] == true)
		{
			cout << "Player wins!" << endl;
			cout << "Play again [Y/N]? ";
		}
		else if (results[5][5] == false)
		{
			cout << "Computer wins!" << endl;
			cout << "Play again [Y/N]? ";
		}
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
	cout << "|| [R] = Rock || [P] = Paper || [S] = Scissors || [L] = Lizard || [K] = Spock ||" << endl;
	cout << "||----------------------------------------------------------------------------||" << endl;
	cout << "||____________________________________________________________________________||" << endl;
	cout << endl; //formatting

}

void QuitOptions()
{

}

void HowToPlay()
{

}