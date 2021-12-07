#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char DisplayMenu(); //shows menu
void MenuOptions(char menuInput); //sorts the input
void MainInput();
char PlayerInput (); 
int CompInput();
void CheckResult(char playerMove, char compIn);
void HowToPlay(); //instructions
void DisplayGameOptions(); //displays the options a user can put in
void InitialiseGame();
void QuitOptions();

bool gameActive = false; //so the game can be replayed
bool goodInput = false;

char InputOptions[5] = {'R', 'P', 'S', 'L', 'K'}; //array to hold the options

int main()
{
	while (goodInput == false) {
		MenuOptions(DisplayMenu());
	}
	while (gameActive == true) {
		//replays when option is selected
		MainInput();
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

void MainInput()
{
	CheckResult();
}

char PlayerInput()
{
	char selectInput;

	InitialiseGame();

	cout << "Choose your move: ";
	cin >> selectInput;

	switch (selectInput) {
		case 'R':
		case 'r':
			selectInput = InputOptions[0];
			break;
		case 'P':
		case 'p':
			selectInput = InputOptions[1];
			break;
		case 'S':
		case 's':
			selectInput = InputOptions[2];
			break;
		case 'L':
		case 'l':
			selectInput = InputOptions[3];
			break;
		case 'k':
		case 'K':
			selectInput = InputOptions[4];
			break;
	}
	
	return selectInput;
}

int CompInput()
{
	int compIn = 0;

	compIn = rand() % 4;

	if (compIn == 0)
	{
		compIn = InputOptions[0];
	}
	else if (compIn == 1)
	{
		compIn = InputOptions[1];
	}
	else if (compIn == 2)
	{
		compIn = InputOptions[2];
	}
	else if (compIn == 3)
	{
		compIn = InputOptions[3];
	}
	else if (compIn == 4)
	{
		compIn = InputOptions[4];
	}

	return compIn;
}

void CheckResult(char selectInput, char compIn)
{
	if (compIn == selectInput)
	{
		cout << endl; //formatting
		cout << "Draw!";
		cout << "Would you like to play again (Y/N)? ";
	}
	else if (compIn == 0 && selectInput == 1)
	{
		cout << endl;
		cout << "Player Wins!";
		cout << "Would you like to play again (Y/N)? ";
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