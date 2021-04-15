#include <iostream>
#include <Windows.h>
#define CELLS 9

using namespace std;

/*2. КРЕСТИКИ-НОЛИКИ. Запрограммируйте и сыграйте с компьютером в игру "Крестики-нолики".*/
void game();
int getDecency();
char getCrossOrZero(int decency);
char getCrossOrZeroComputer(char player);
void enterField(char field[]);
void gameDecency(char field[], char player, char computer, int decency, int cell);
int getWinСombinations(char field[], char player, char computer, int cell);
bool isWinСombinations(char field[], char element);
bool isWinСombinationsHorizontal(char field[], char element);
bool isWinСombinationVertically(char field[], char element);
bool isWinСombinationDiagonally(char field[], char element);
void enterPlayer(char field[], char player);
void enterComputer(char field[], char computer);
void fieldExample();

bool isChoiceSituation(int situation);
void coutSituation(int situation);
bool isChoice(int choice);
void clearConsole();

int main()
{
	bool isCheck = true;

	while (isCheck)
	{
		game();

		isCheck = isChoiceSituation(1);

		clearConsole();
	}

	cout << "Goodbye! Thank you for playing!" << endl;

	return 0;
}

void game()
{
	char field[CELLS] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, player = 0, computer = 0;
	int decency = 0;

	decency = getDecency();

	player = getCrossOrZero(decency);

	computer = getCrossOrZeroComputer(player);

	for (int cell = 0; cell < CELLS; cell++)
	{
		clearConsole();

		enterField(field);

		gameDecency(field, player, computer, decency, cell);

		clearConsole();

		enterField(field);

		if (getWinСombinations(field, player, computer, cell) == 1)
		{
			break;
		}
		else if (cell == 8)
		{
			cout << "Draw!" << endl;
		}
	}
}

int getWinСombinations(char field[], char player, char computer, int cell)
{
	if (cell > 3)
	{
		if (isWinСombinations(field, player))
		{
			cout << "You win!!!" << endl;

			return 1;
		}
		else if (isWinСombinations(field, computer))
		{
			cout << "You've lost." << endl;

			return 1;
		}
		else return 0;
	}
	else return 0;
}

bool isWinСombinations(char field[], char element)
{
	if (isWinСombinationsHorizontal(field, element))
	{
		return true;
	}
	else if (isWinСombinationVertically(field, element))
	{
		return true;
	}
	else if (isWinСombinationDiagonally(field, element))
	{
		return true;
	}
	else return false;
}

bool isWinСombinationsHorizontal(char field[], char element)
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

bool isWinСombinationVertically(char field[], char element)
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

bool isWinСombinationDiagonally(char field[], char element)
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

void enterField(char field[])
{
	cout << " " << field[6] << " | " << field[7] << " | " << field[8] << endl
		 << "---+---+---" << endl
		 << " " << field[3] << " | " << field[4] << " | " << field[5] << endl
		 << "---+---+---" << endl
		 << " " << field[0] << " | " << field[1] << " | " << field[2] << endl << endl;
}

void gameDecency(char field[], char player, char computer, int decency, int cell)
{
	if ((decency + cell) % 2 == 0)
	{
		cout << "Your move. You " << player << "." << endl << endl;

		fieldExample();

		enterPlayer(field, player);
	}
	else
	{
		cout << "Computer move." << endl;
		Sleep(3000);

		enterComputer(field, computer);
	}
}

void fieldExample()
{
	cout << "'7'|'8'|'9'" << endl
		 << "---+---+---" << endl
		 << "'4'|'5'|'6'" << endl
		 << "---+---+---" << endl
		 << "'1'|'2'|'3'" << endl << endl;
}

void enterComputer(char field[], char computer)
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

void enterPlayer(char field[], char player)
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
	if (isChoiceSituation(2))
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

bool isChoiceSituation(int situation)
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
			return isChoice(choice);
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

bool isChoice(int choice)
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