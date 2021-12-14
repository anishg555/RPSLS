//  Written by Anish Gautam (P2657398)

#include <iostream>
#include <stdlib.h>

using namespace std;

char DisplayMenu(); //shows menu
void MenuOptions(char menuInput); //sorts the input
void MainGameInput(); //combines the following instructions into one to make int main neater
void InitialiseGame(); // sets up the game layout
void DisplayGameOptions(); //displays the options a user can put in
int PlayerInput(); //allows player to select an option
int ShowPlayerInput(int playerIn);
int CompInput(); //allows randomised computer input
int ShowCompInput(int compInput); //displays computer input
void CheckResult(int playerIn, int compIn); //sorts and displays results
void GameEnd(); //allows player to return or continue
void GameInfo(); //instructions
void QuitOptions(); //allows user to quit

bool gameActive = false; //so the game can be replayed
bool goodInput = false;

bool gameResult; //for the array later on
char continueGame;

//the array:
bool results[5][5] =    //rock, paper, scis, lzrd, spock - player
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
	cout << "|| [I] Game information             ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "|| [Q] Exit game                    ||" << endl;
	cout << "||----------------------------------||" << endl;
	cout << "||__________________________________||" << endl;
	cout << endl; // formatting

	cout << "Please enter the command you would like to use: ";
	cin >> menuInput;

	return menuInput; //for the switch statement in the next variable

}

void MenuOptions(char menuInput)
{
	switch (menuInput) {
	case 'P':
	case 'p':
		goodInput = true; //having good input as true means the menu doesn't continue to show
		MainGameInput();
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
		goodInput = false; //returns to menu
		break;
	}
}

void MainGameInput()
{
	CheckResult(CompInput(), PlayerInput());
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

int PlayerInput()
{
	int playerIn = 0;

	InitialiseGame();

	cout << "Choose your move: ";
	cin >> playerIn;

	if (playerIn > 4 || playerIn < 0)
	{
		// prevents bad numerical input

		cout << "Invalid Input!" << endl;
		system("pause");
		PlayerInput();
	}

	if (!playerIn)
	{
		if (playerIn == 0) {
			return playerIn;
		}
		else {
			cout << "Invalid Input! ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this deletes the input, and prevents it from being entered

			system("pause");
			PlayerInput();
		}
	}

	ShowPlayerInput(playerIn);

	return playerIn;
}

int ShowPlayerInput(int playerIn)
{
	if (playerIn == 0)
	{
		cout << "You have chosen rock!" << endl;
		return playerIn;
	}
	else
	{
		switch (playerIn) {
		case 1:
			cout << "You have chosen paper!" << endl;
		break;
		case 2:
			cout << "You have chosen scissors!" << endl;
		break;
		case 3:
			cout << "You have chosen lizard!" << endl;
		break;
		case 4:
			cout << "You have chosen Spock!" << endl;
		break;
		default:
			cout << "Invalid Input! " << endl;
			system("pause");
			PlayerInput();
			break;
		}
	}

	return playerIn;
}

int CompInput()
{
	int compIn = 0; //initialises variable

	compIn = rand() % 5; //random number selection between 0-4, for use in the array

	ShowCompInput(compIn);

	return compIn;
	
}

int ShowCompInput(int compIn)
{
	//displays to the user what the computer has chosen so they know how they won/lost

	switch (compIn) {
	case 0:
		cout << "Computer has used rock!" << endl;
		break;
	case 1:
		cout << "Computer has used paper!" << endl;
		break;
	case 2:
		cout << "Computer has used scissors!" << endl;
		break;
	case 3:
		cout << "Computer has used lizard!" << endl;
		break;
	case 4:
		cout << "Computer has used Spock!" << endl;
		break;
	default:
		break;
	}
	return compIn;
}

void CheckResult(int playerIn, int compIn)
{
	//prevent ties

	if (playerIn == compIn)
	{
		cout << "Draw!" << endl;

		GameEnd();

	}
	else
	{
		gameResult = results[playerIn][compIn];

		if (gameResult == true)
		{
			cout << "Player wins!" << endl;

			GameEnd();

		}
		else if (gameResult == false)
		{
			cout << "Computer wins!" << endl;

			GameEnd();

		}
	}
}

void GameEnd()
{
	cout << "Play again [Y/N]? ";
	cin >> continueGame;

	switch (continueGame) {
	case 'Y':
	case 'y':
		MainGameInput(); //continues game
		break;
	case 'N':
	case 'n':
		gameActive = false;
		goodInput = false; //returns to menu
		break;
	default:
		cout << "Invalid Input! ";
		GameEnd(); //resets game end function
		break;
	}
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

void QuitOptions()
{
	goodInput = true; //prevents menu from showing

	cout << "Thank you for playing. ";
	system("pause");
	return;
}
