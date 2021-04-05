#include <iostream>
#include <Windows.h>
#define CELLS 9

using namespace std;

/*2. КРЕСТИКИ-НОЛИКИ. Запрограммируйте и сыграйте с компьютером в игру "Крестики-нолики".*/
void getGame();
int getDecency();
char getCrossOrZero(int decency);
char getCrossOrZeroComputer(char player);
void getField(char field[]);
void getGameDecency(char field[], char player, char computer, int decency, int cell);
int getRulesGame(char field[], char player, char computer, int cell);
bool getWinСombinations(char field[], char element);
bool getWinСombinationsHorizontal(char field[], char element);
bool getWinСombinationVertically(char field[], char element);
bool getWinСombinationDiagonally(char field[], char element);
void getEnterPlayer(char field[], char player);
void getEnterComputer(char field[], char computer);
void getFieldEnter();

bool getIsChoiceSituation(int situation);
void coutSituation(int situation);
bool getIsChoice(int choice);
void clearConsole();

int main()
{
	bool isCheak = true;

	while (isCheak)
	{
		getGame();

		isCheak = getIsChoiceSituation(1);

		clearConsole();
	}

	cout << "Goodbye! Thank you for playing!" << endl;

	return 0;
}

void getGame()
{
	char field[CELLS] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, player = 0, computer = 0;
	int decency = 0;

	decency = getDecency();

	player = getCrossOrZero(decency);

	computer = getCrossOrZeroComputer(player);

	for (int cell = 0; cell < CELLS; cell++)
	{
		clearConsole();

		getField(field);

		getGameDecency(field, player, computer, decency, cell);

		clearConsole();

		getField(field);

		if (getRulesGame(field, player, computer, cell) == 1)
		{
			break;
		}
		else if (cell == 8)
		{
			cout << "Draw!" << endl;
		}
	}
}

int getRulesGame(char field[], char player, char computer, int cell)
{
	if (cell > 3)
	{
		if (getWinСombinations(field, player))
		{
			cout << "You win!!!" << endl;

			return 1;
		}
		else if (getWinСombinations(field, computer))
		{
			cout << "You've lost." << endl;

			return 1;
		}
		else return 0;
	}
	else return 0;
}

bool getWinСombinations(char field[], char element)
{
	if (getWinСombinationsHorizontal(field, element))
	{
		return true;
	}
	else if (getWinСombinationVertically(field, element))
	{
		return true;
	}
	else if (getWinСombinationDiagonally(field, element))
	{
		return true;
	}
	else return false;
}

bool getWinСombinationsHorizontal(char field[], char element)
{
	for (int cell = 0; cell < CELLS; cell += 3)
	{
		if ((field[cell] == element) and (field[cell + 1] == element) and (field[cell + 2] == element))
		{
			return true;
		}
		else {}
	}
	return false;
}

bool getWinСombinationVertically(char field[], char element)
{
	for (int cell = 0; cell < 3; cell++)
	{
		if ((field[cell] == element) and (field[cell + 3] == element) and (field[cell + 6] == element))
		{
			return true;
		}
		else {}
	}
	return false;
}

bool getWinСombinationDiagonally(char field[], char element)
{
	if ((field[0] == element) and (field[4] == element) and (field[8] == element))
	{
		return true;
	}
	else if ((field[2] == element) and (field[4] == element) and (field[6] == element))
	{
		return true;
	}
	else return false;
}

void getField(char field[])
{
	cout << " " << field[6] << " | " << field[7] << " | " << field[8] << endl
		 << "---+---+---" << endl
		 << " " << field[3] << " | " << field[4] << " | " << field[5] << endl
		 << "---+---+---" << endl
		 << " " << field[0] << " | " << field[1] << " | " << field[2] << endl << endl;
}

void getGameDecency(char field[], char player, char computer, int decency, int cell)
{
	if ((decency + cell) % 2 == 0)
	{
		cout << "Your move. You " << player << "." << endl << endl;

		getFieldEnter();

		getEnterPlayer(field, player);
	}
	else
	{
		cout << "Computer move." << endl;
		Sleep(3000);

		getEnterComputer(field, computer);
	}
}

void getFieldEnter()
{
	cout << "'7'|'8'|'9'" << endl
		 << "---+---+---" << endl
		 << "'4'|'5'|'6'" << endl
		 << "---+---+---" << endl
		 << "'1'|'2'|'3'" << endl << endl;
}

void getEnterComputer(char field[], char computer)
{
	int number = 0;

	while (true)
	{
		number = 1 + rand() % 9;

		if (field[number - 1] == ' ')
		{
			field[number - 1] = computer;
			break;
		}
		else {}
	}
}

void getEnterPlayer(char field[], char player)
{
	int number = 0;

	while (true)
	{
		cout << "Select cell: ";
		cin >> number;

		if (!cin)
		{
			cout << "Incorrect input number!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else if (number < 1 or number > 9)
		{
			cout << "There is no such cell!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else if (field[number - 1] == 'x' or field[number - 1] == 'o')
		{
			cout << "This cell is occupied!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else
		{
			field[number - 1] = player;
			break;
		}
	}
}

int getDecency()
{
	if (getIsChoiceSituation(2))
	{
		return 0;
	}
	else return 1;
}

char getCrossOrZero(int decency)
{
	if (decency == 0)
	{
		return 'x';
	}
	else return 'o';
}

char getCrossOrZeroComputer(char player)
{
	if (player == 'o')
	{
		return 'x';
	}
	else return 'o';
}

bool getIsChoiceSituation(int situation)
{
	int choice = 0;

	while (true)
	{
		coutSituation(situation);
		cin >> choice;

		if (!cin)
		{
			clearConsole();
			cout << "Incorrect input number!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else if (choice == 0 or choice == 1)
		{
			return getIsChoice(choice);
		}
		else clearConsole();
	}
}

void coutSituation(int situation)
{
	if (situation == 1)
	{
		cout << "Play it again? (1 - Yes, 0 - No): ";
	}
	else if (situation == 2)
	{
		cout << "Will you go first? (1 - Yes, 0 - No): ";
	}
	else {}
}

bool getIsChoice(int choice)
{
	if (choice == 1)
	{
		return true;
	}
	else return false;
}

void clearConsole() {
	system("CLS");
}