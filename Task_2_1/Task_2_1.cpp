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
void enterComputer(char field[], char computer, int cell);
void input(char field[], char computer);
void case0(char field[], char computer);
void case1(char field[], char computer);
void case2(char field[]);
void case2Player4(char field[], int comp);
void case2Comp8(char field[], int player);
void case2Comp6(char field[], int player);
void case2Comp2(char field[], int player);
void case2Comp0(char field[], int player);
void case3(char field[], char computer);
void case3Comp4(char field[], char player, char player1, char computer);
void case3Player4(char field[], char player, char player1, char comp, char computer);
void case3Comp4Player6(char field[], char player1, char computer);
void case3Comp4Player5(char field[], char player1, char computer);
void case3Comp4Player3(char field[], char player1, char computer);
void case3Comp4Player2(char field[], char player1, char computer);
void case3Comp4Player1(char field[], char player1, char computer);
void case3Comp4Player0(char field[], char player1, char computer);
void case4(char field[]);
void case4Comp68(char field[], int player, int player1);
void case4Comp28(char field[], int player, int player1);
void case4Comp06(char field[], int player, int player1);
void case4Comp02(char field[], int player, int player1);
void case5(char field[], char computer);
void case5x4(char field[], char computer);
void case5x4o1(char field[], char computer, int comp, int comp1);
void case5x4o3(char field[], char computer, int comp, int comp1);
void case5x4o5(char field[], char computer, int comp, int comp1);
void case5x4o7(char field[], char computer, int comp, int comp1);
void case5x4Comp06(char field[], char computer);
void case5x4Comp68(char field[], char computer);
void case5x4Comp28(char field[], char computer);
void case5x4Comp02(char field[], char computer);
void case5o4(char field[], char computer);
void case5o4Comp18(char field[], char computer, int player1);
void case5o4Comp17(char field[], char computer);
void case5o4Comp16(char field[], char computer, int player, int player2);
void case5o4Comp15(char field[], char computer);
void case5o4Comp3(char field[], char computer, int player, int player2);
void case5o4Comp2(char field[], char computer, int player);
void case5o4Comp1(char field[], char computer);
void case5o4Comp0(char field[], char computer, int player, int player1);
int getx2Cell(char field[], int comp, int comp1);
void case6(char field[]);
void case6x4Win(char field[], int comp, int comp1);
void case6o4Win(char field[], int comp1);
void case6o4(char field[], int comp1);
void case7(char field[], char computer);
void case7o4(char field[], char computer);
void case7o4Draw(char field[], char computer);
bool isCase7o4Win(char field[], char computer);
void case7x4(char field[], char computer);
void case7x4Draw(char field[], char computer);
void emptyCell(char field[], char computer);
bool isCase7x4Win(char field[], char computer);
int geto1Cell(char field[], int player);
int getx1Cell(char field[], int comp);

int getxCell(char field[]);
int getoCell(char field[]);

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

		enterComputer(field, computer, cell);
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

void enterComputer(char field[], char computer, int cell)
{
	switch (cell)
	{
	case 0:
	{
		case0(field, computer);
		break;
	}
	case 1:
	{
		case1(field, computer);
		break;
	}
	case 2:
	{
		case2(field);
		break;
	}
	case 3:
	{
		case3(field, computer);
		break;
	}
	case 4:
	{
		case4(field);
		break;
	}
	case 5:
	{
		case5(field, computer);
		break;
	}
	case 6:
	{
		case6(field);
		break;
	}
	case 7:
	{
		case7(field, computer);
		break;
	}
	default:
		input(field, computer);
		break;
	}
}

void case7(char field[], char computer)
{
	if (field[4] == computer)
	{
		case7o4(field, computer);
	}
	else case7x4(field, computer);
}

void case7o4(char field[], char computer)
{
	if (isCase7o4Win(field, computer))
	{
		case7o4Draw(field, computer);
	}
}

void case7o4Draw(char field[], char computer)
{
	if (field[0] == 'x' and field[2] == 'x' and field[1] == ' ')
	{
		field[1] = computer;
	}
	else if (field[2] == 'x' and field[8] == 'x' and field[5] == ' ')
	{
		field[5] = computer;
	}
	else if (field[6] == 'x' and field[8] == 'x' and field[7] == ' ')
	{
		field[7] = computer;
	}
	else if (field[0] == 'x' and field[6] == 'x' and field[3] == ' ')
	{
		field[3] = computer;
	}
	else if (field[0] == 'x' and field[1] == 'x' and field[2] == ' ')
	{
		field[2] = computer;
	}
	else if (field[1] == 'x' and field[2] == 'x' and field[0] == ' ')
	{
		field[0] = computer;
	}
	else if (field[0] == 'x' and field[3] == 'x' and field[6] == ' ')
	{
		field[6] = computer;
	}
	else if (field[3] == 'x' and field[6] == 'x' and field[0] == ' ')
	{
		field[0] = computer;
	}
	else if (field[6] == 'x' and field[7] == 'x' and field[8] == ' ')
	{
		field[8] = computer;
	}
	else if (field[7] == 'x' and field[8] == 'x' and field[6] == ' ')
	{
		field[6] = computer;
	}
	else if (field[2] == 'x' and field[5] == 'x' and field[8] == ' ')
	{
		field[8] = computer;
	}
	else if (field[5] == 'x' and field[8] == 'x' and field[2] == ' ')
	{
		field[2] = computer;
	}
	else
	{
		emptyCell(field, computer);
	}
}

bool isCase7o4Win(char field[], char computer)
{
	if (field[0] == computer and field[2] == computer and field[1] == ' ')
	{
		field[1] = computer;
		return false;
	}
	else if (field[2] == computer and field[8] == computer and field[5] == ' ')
	{
		field[5] = computer;
		return false;
	}
	else if (field[6] == computer and field[8] == computer and field[7] == ' ')
	{
		field[7] = computer;
		return false;
	}
	else if (field[0] == computer and field[6] == computer and field[3] == ' ')
	{
		field[3] = computer;
		return false;
	}
	else if (field[0] == computer and field[1] == computer and field[2] == ' ')
	{
		field[2] = computer;
		return false;
	}
	else if (field[1] == computer and field[2] == computer and field[0] == ' ')
	{
		field[0] = computer;
		return false;
	}
	else if (field[0] == computer and field[3] == computer and field[6] == ' ')
	{
		field[6] = computer;
		return false;
	}
	else if (field[3] == computer and field[6] == computer and field[0] == ' ')
	{
		field[0] = computer;
		return false;
	}
	else if (field[6] == computer and field[7] == computer and field[8] == ' ')
	{
		field[8] = computer;
		return false;
	}
	else if (field[7] == computer and field[8] == computer and field[6] == ' ')
	{
		field[6] = computer;
		return false;
	}
	else if (field[2] == computer and field[5] == computer and field[8] == ' ')
	{
		field[8] = computer;
		return false;
	}
	else if (field[5] == computer and field[8] == computer and field[2] == ' ')
	{
		field[2] = computer;
		return false;
	}
	else if (field[0] == computer and field[8] == ' ')
	{
		field[8] = computer;
		return false;
	}
	else if (field[1] == computer and field[7] == ' ')
	{
		field[7] = computer;
		return false;
	}
	else if (field[2] == computer and field[6] == ' ')
	{
		field[6] = computer;
		return false;
	}
	else if (field[3] == computer and field[5] == ' ')
	{
		field[5] = computer;
		return false;
	}
	else if (field[5] == computer and field[3] == ' ')
	{
		field[3] = computer;
		return false;
	}
	else if (field[6] == computer and field[2] == ' ')
	{
		field[2] = computer;
		return false;
	}
	else if (field[7] == computer and field[1] == ' ')
	{
		field[1] = computer;
		return false;
	}
	else if (field[8] == computer and field[0] == ' ')
	{
		field[0] = computer;
		return false;
	}
	else return true;
}

void case7x4(char field[], char computer)
{
	if (isCase7x4Win(field, computer))
	{
		case7x4Draw(field, computer);
	}
	else {}
}

void case7x4Draw(char field[], char computer)
{
	if (field[0] == 'x' and field[8] == ' ')
	{
		field[8] = computer;
	}
	else if (field[1] == 'x' and field[7] == ' ')
	{
		field[7] = computer;
	}
	else if (field[2] == 'x' and field[6] == ' ')
	{
		field[6] = computer;
	}
	else if (field[3] == 'x' and field[5] == ' ')
	{
		field[5] = computer;
	}
	else if (field[5] == 'x' and field[3] == ' ')
	{
		field[3] = computer;
	}
	else if (field[6] == 'x' and field[2] == ' ')
	{
		field[2] = computer;
	}
	else if (field[7] == 'x' and field[2] == ' ')
	{
		field[2] = computer;
	}
	else if (field[1] == 'x' and field[8] == ' ')
	{
		field[8] = computer;
	}
	else
	{
		emptyCell(field, computer);
	}
}

void emptyCell(char field[], char computer)
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == ' ')
		{
			field[cell] = computer;
			break;
		}
	}
}

bool isCase7x4Win(char field[], char computer)
{
	if (field[0] == computer and field[2] == computer and field[1] == ' ')
	{
		field[1] = computer;
		return false;
	}
	else if (field[2] == computer and field[8] == computer and field[5] == ' ')
	{
		field[5] = computer;
		return false;
	}
	else if (field[6] == computer and field[8] == computer and field[7] == ' ')
	{
		field[7] = computer;
		return false;
	}
	else if (field[0] == computer and field[6] == computer and field[3] == ' ')
	{
		field[3] = computer;
		return false;
	}
	else if (field[0] == computer and field[1] == computer and field[2] == ' ')
	{
		field[2] = computer;
		return false;
	}
	else if (field[1] == computer and field[2] == computer and field[0] == ' ')
	{
		field[0] = computer;
		return false;
	}
	else if (field[0] == computer and field[3] == computer and field[6] == ' ')
	{
		field[6] = computer;
		return false;
	}
	else if (field[3] == computer and field[6] == computer and field[0] == ' ')
	{
		field[0] = computer;
		return false;
	}
	else if (field[6] == computer and field[7] == computer and field[8] == ' ')
	{
		field[8] = computer;
		return false;
	}
	else if (field[7] == computer and field[8] == computer and field[6] == ' ')
	{
		field[6] = computer;
		return false;
	}
	else if (field[2] == computer and field[5] == computer and field[8] == ' ')
	{
		field[8] = computer;
		return false;
	}
	else if (field[5] == computer and field[8] == computer and field[2] == ' ')
	{
		field[2] = computer;
		return false;
	}
	else return true;
}

void case5(char field[], char computer)
{
	if (field[4] == computer)
	{
		case5o4(field, computer);
	}
	else case5x4(field, computer);
}

void case5x4(char field[], char computer)
{
	int player = getxCell(field), comp = getoCell(field);
	int player1 = getx1Cell(field, player), comp1 = geto1Cell(field, comp);
	int player2 = getx2Cell(field, player, player1);

	if (comp == 0 and comp1 == 2)
	{
		case5x4Comp02(field, computer);
	}
	else if(comp == 2 and comp1 == 8)
	{
		case5x4Comp28(field, computer);
	}
	else if (comp == 6 and comp1 == 8)
	{
		case5x4Comp68(field, computer);
	}
	else if (comp == 0 and comp1 == 6)
	{
		case5x4Comp06(field, computer);
	}
	else if (field[7] == 'o')
	{
		case5x4o7(field, computer, comp, comp1);
	}
	else if (field[5] == 'o')
	{
		case5x4o5(field, computer, comp, comp1);
	}
	else if (field[3] == 'o')
	{
		case5x4o3(field, computer, comp, comp1);
	}
	else case5x4o1(field, computer, comp, comp1);
}

void case5x4o1(char field[], char computer, int comp, int comp1)
{
	int player = getxCell(field);
	int player1 = getx1Cell(field, player);
	int player2 = getx2Cell(field, player, player1);

	if (comp == 0)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[6] = computer;
	}
	else if (comp1 == 2)
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[8] = computer;
	}
	else if (player == 0)
	{
		if (field[8] == ' ')
		{
			field[8] = computer;
		}
		else field[2] = computer;
	}
	else if (player == 2)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[0] = computer;
	}
	else if (player == 3)
	{
		field[5] = computer;
	}
	else if (player1 == 5)
	{
		field[3] = computer;
	}
	else if (player1 == 6)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[8] = computer;
	}
	else
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[6] = computer;
	}
}

void case5x4o3(char field[], char computer, int comp, int comp1)
{
	int player = getxCell(field);
	int player1 = getx1Cell(field, player);
	int player2 = getx2Cell(field, player, player1);

	if (comp1 == 6)
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[8] = computer;
	}
	else if (comp == 0)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[2] = computer;
	}
	else if (player == 0)
	{
		if (field[8] == ' ')
		{
			field[8] = computer;
		}
		else field[6] = computer;
	}
	else if (player == 1)
	{
		field[7] = computer;
	}
	else if (player == 2)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[8] = computer;
	}
	else if (player2 == 6)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[0] = computer;
	}
	else if (player2 == 7)
	{
		field[1] = computer;
	}
	else
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[2] = computer;
	}
}

void case5x4o5(char field[], char computer, int comp, int comp1)
{
	int player = getxCell(field);
	int player1 = getx1Cell(field, player);
	int player2 = getx2Cell(field, player, player1);

	if (comp == 2)
	{
		if (field[8] == ' ')
		{
			field[8] = computer;
		}
		else field[0] = computer;
	}
	else if (comp1 == 8)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[6] = computer;
	}
	else if (player == 0)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[8] = computer;
	}
	else if (player == 1)
	{
		field[7] = computer;
	}
	else if (player == 2)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[8] = computer;
	}
	else if (player2 == 6)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[0] = computer;
	}
	else if (player2 == 7)
	{
		field[1] = computer;
	}
	else
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[2] = computer;
	}
}

void case5x4o7(char field[], char computer, int comp, int comp1)
{
	int player = getxCell(field);
	int player1 = getx1Cell(field, player);
	int player2 = getx2Cell(field, player, player1);

	if (comp == 6)
	{
		if (field[8] == ' ')
		{
			field[8] = computer;
		}
		else field[0] = computer;
	}
	else if (comp1 == 8)
	{
		if (field[6] == ' ')
		{
			field[6] = computer;
		}
		else field[2] = computer;
	}
	else if (player == 0)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[8] = computer;
	}
	else if (player1 == 2)
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[6] = computer;
	}
	else if (player1 == 3)
	{
		field[5] = computer;
	}
	else if (player2 == 5)
	{
		field[3] = computer;
	}
	else if (player2 == 6)
	{
		if (field[2] == ' ')
		{
			field[2] = computer;
		}
		else field[8] = computer;
	}
	else
	{
		if (field[0] == ' ')
		{
			field[0] = computer;
		}
		else field[6] = computer;
	}
}

void case5x4Comp06(char field[], char computer)
{
	if (field[3] == ' ')
	{
		field[3] = computer;
	}
	else field[5] = computer;
}

void case5x4Comp68(char field[], char computer)
{
	if (field[7] == ' ')
	{
		field[7] = computer;
	}
	else field[1] = computer;
}

void case5x4Comp28(char field[], char computer)
{
	if (field[5] == ' ')
	{
		field[5] = computer;
	}
	else field[3] = computer;
}

void case5x4Comp02(char field[], char computer)
{
	if (field[1] == ' ')
	{
		field[1] = computer;
	}
	else field[7] = computer;
}

void case5o4(char field[], char computer)
{
	int player = getxCell(field), comp = getoCell(field);
	int player1 = getx1Cell(field, player), comp1 = geto1Cell(field, comp);
	int player2 = getx2Cell(field, player, player1);

	if (comp == 0)
	{
		case5o4Comp0(field, computer, player, player1);
	}
	else if (comp == 1)
	{
		case5o4Comp1(field, computer);
	}
	else if (comp == 2)
	{
		case5o4Comp2(field, computer, player);
	}
	else if (comp == 3)
	{
		case5o4Comp3(field, computer, player, player2);
	}
	else if (comp1 == 5)
	{
		case5o4Comp15(field, computer);
	}
	else if (comp1 == 6)
	{
		case5o4Comp16(field, computer, player, player2);
	}
	else if (comp1 == 7)
	{
		case5o4Comp17(field, computer);
	}
	else 
	{
		case5o4Comp18(field, computer, player1);
	}
}

void case5o4Comp18(char field[], char computer, int player1)
{
	if (field[0] == ' ')
	{
		field[0] = computer;
	}
	else if (player1 == 2)
	{
		field[1] = computer;
	}
	else field[3] = computer;
}

void case5o4Comp17(char field[], char computer)
{
	if (field[1] == ' ')
	{
		field[1] = computer;
	}
	else field[5] = computer;
}

void case5o4Comp16(char field[], char computer, int player, int player2)
{
	if (field[2] == ' ')
	{
		field[2] = computer;
	}
	else if (player == 0)
	{
		field[1] = computer;
	}
	else if (player2 != 8)
	{
		field[8] = computer;
	}
	else field[5] = computer;
}

void case5o4Comp15(char field[], char computer)
{
	if (field[5] == ' ')
	{
		field[5] = computer;
	}
	else field[1] = computer;
}

void case5o4Comp3(char field[], char computer, int player, int player2)
{
	if (field[5] == ' ')
	{
		field[5] = computer;
	}
	else if (player == 2)
	{
		field[8] = computer;
	}
	else if (player2 == 6)
	{
		field[1] = computer;
	}
	else field[2] = computer;
}

void case5o4Comp2(char field[], char computer, int player)
{
	if (field[6] == ' ')
	{
		field[6] = computer;
	}
	else if (player == 0)
	{
		field[3] = computer;
	}
	else field[7] = computer;
}

void case5o4Comp1(char field[], char computer)
{
	if (field[7] == ' ')
	{
		field[7] = computer;
	}
	else field[3] = computer;
}

void case5o4Comp0(char field[], char computer, int player, int player1)
{
	if (field[8] == ' ')
	{
		field[8] = computer;
	}
	else if (player == 2)
	{
		field[5] = computer;
	}
	else if (player1 == 6)
	{
		field[7] = computer;
	}
	else field[7] = computer;
}

int getx2Cell(char field[], int comp, int comp1)
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == 'x' and cell != comp)
		{
			if (field[cell] == 'x' and cell != comp1)
			{
				return cell;
			}
			else {}
		}
		else {}
	}
}

void case3(char field[], char computer)
{
	int player = getxCell(field), comp = getoCell(field);
	int player1 = getx1Cell(field, player);

	if (comp == 4)
	{
		case3Comp4(field, player, player1, computer);
	}
	else case3Player4(field, player, player1, comp, computer);
}

void case3Player4(char field[], char player, char player1, char comp, char computer)
{
	if (player == 0)
	{
		if (comp == 8)
		{
			field[6] = computer;
		}
		else field[8] = computer;
	}
	else if (player == 1)
	{
		field[7] = computer;
	}
	else if (player == 2)
	{
		if (comp == 6)
		{
			field[8] = computer;
		}
		else field[6] = computer;
	}
	else if (player == 3)
	{
		field[5] = computer;
	}
	else if (player1 == 5)
	{
		field[3] = computer;
	}
	else if (player1 == 6)
	{
		if (comp == 2)
		{
			field[0] = computer;
		}
		else field[2] = computer;
	}
	else if (player1 == 7)
	{
		field[1] = computer;
	}
	else
	{
		if (comp == 0)
		{
			field[2] = computer;
		}
		else field[0] = computer;
	}
}

void case3Comp4(char field[], char player, char player1, char computer)
{
	if (player == 0)
	{
		case3Comp4Player0(field, player1, computer);
	}
	else if (player == 1)
	{
		case3Comp4Player1(field, player1, computer);
	}
	else if (player == 2)
	{
		case3Comp4Player2(field, player1, computer);
	}
	else if (player == 3)
	{
		case3Comp4Player3(field, player1, computer);
	}
	else if (player == 5)
	{
		case3Comp4Player5(field, player1, computer);
	}
	else if (player == 6)
	{
		case3Comp4Player6(field, player1, computer);
	}
	else field[6] = computer;
}

void case3Comp4Player6(char field[], char player1, char computer)
{
	if (player1 == 8)
	{
		field[7] = computer;
	}
	else field[8] = computer;
}


void case3Comp4Player5(char field[], char player1, char computer)
{
	if (player1 == 8)
	{
		field[2] = computer;
	}
	else field[8] = computer;
}

void case3Comp4Player3(char field[], char player1, char computer)
{
	if (player1 == 6)
	{
		field[0] = computer;
	}
	else field[6] = computer;
}

void case3Comp4Player2(char field[], char player1, char computer)
{
	if (player1 == 5 or player1 == 7)
	{
		field[8] = computer;
	}
	else if (player1 == 8)
	{
		field[5] = computer;
	}
	else if (player1 == 3)
	{
		field[0] = computer;
	}
	else field[3] = computer;
}

void case3Comp4Player1(char field[], char player1, char computer)
{
	if (player1 == 2 or player1 == 3 or player1 == 6 or player1 == 7)
	{
		field[0] = computer;
	}
	else field[2] = computer;
}

void case3Comp4Player0(char field[], char player1, char computer)
{
	if (player1 == 1 or player1 == 5)
	{
		field[2] = computer;
	}
	else if (player1 == 2)
	{
		field[1] = computer;
	}
	else if (player1 == 3 or player1 == 7)
	{
		field[6] = computer;
	}
	else field[3] = computer;
}

void case1(char field[], char computer)
{
	if (field[4] == 'x')
	{
		case0(field, computer);
	}
	else field[4] = computer;
}

void case6(char field[])
{
	int player = getoCell(field), comp = getxCell(field);
	int player1 = geto1Cell(field, player), comp1 = getx1Cell(field, comp);

	if (field[4] == 'o')
	{
		if (comp % 2 == 0 and comp1 % 2 == 0)
		{
			case6o4Win(field, comp1);
		}
		else case6o4(field, comp1);
	}
	else case6x4Win(field, comp, comp1);
}

void case6x4Win(char field[], int comp, int comp1)
{
	if (comp == 0 and comp1 == 2)
	{
		if (field[6] == 'o')
		{
			field[8] = 'x';
		}
		else field[6] = 'x';
	}
	else if(comp == 2 and comp1 == 4)
	{
		if (field[0] == 'o')
		{
			field[6] = 'x';
		}
		else field[0] = 'x';
	}
	else if (comp == 4 and comp1 == 6)
	{
		if (field[0] == 'o')
		{
			field[2] = 'x';
		}
		else field[0] = 'x';
	}
	else
	{
		if (field[2] == 'o')
		{
			field[8] = 'x';
		}
		else field[2] = 'x';
	}
}

void case6o4Win(char field[], int comp1)
{
	if (comp1 == 2)
	{
		if (field[1] == 'o')
		{
			field[5] = 'x';
		}
		else field[1] = 'x';
	}
	else
	{
		if (field[3] == 'o')
		{
			field[7] = 'x';
		}
		else field[3] = 'x';
	}
}

void case6o4(char field[], int comp1)
{
	if (comp1 % 2 == 1)
	{
		if (field[7] == 'o')
		{
			field[1] = 'x';
		}
		else field[7] = 'x';
	}
	else
	{
		if (field[3] == 'o')
		{
			field[5] = 'x';
		}
		else field[3] = 'x';
	}
}

void case4(char field[])
{
	int player = getoCell(field), comp = getxCell(field);
	int player1 = geto1Cell(field, player), comp1 = getx1Cell(field, comp);

	if (comp == 0 and comp1 == 2)
	{
		case4Comp02(field, player, player1);
	}
	else if (comp == 0 and comp1 == 6)
	{
		case4Comp06(field, player, player1);
	}
	else if (comp == 2 and comp1 == 8)
	{
		case4Comp28(field, player, player1);
	}
	else
	{
		case4Comp68(field, player, player1);
	}
}

void case4Comp68(char field[], int player, int player1)
{
	if (field[7] == ' ')
	{
		field[7] = 'x';
	}
	else if (player1 % 2 == 1 and player % 2 == 1)
	{
		field[4] = 'x';
	}
	else if (field[4] == 'o')
	{
		field[1] = 'x';
	}
	else if (field[0] == 'o')
	{
		field[6] = 'x';
	}
	else field[0] = 'x';
}

void case4Comp28(char field[], int player, int player1)
{
	if (field[5] == ' ')
	{
		field[5] = 'x';
	}
	else if (player1 % 2 == 1 and player % 2 == 1)
	{
		field[4] = 'x';
	}
	else if (field[4] == 'o')
	{
		field[3] = 'x';
	}
	else if (field[0] == 'o')
	{
		field[6] = 'x';
	}
	else field[0] = 'x';
}

void case4Comp06(char field[], int player, int player1)
{
	if (field[3] == ' ')
	{
		field[3] = 'x';
	}
	else if (player1 % 2 == 1 and player % 2 == 1)
	{
		field[4] = 'x';
	}
	else if (field[4] == 'o')
	{
		field[5] = 'x';
	}
	else if (field[8] == 'o')
	{
		field[2] = 'x';
	}
	else field[8] = 'x';
}

void case4Comp02(char field[], int player, int player1)
{
	if (field[1] == ' ')
	{
		field[1] = 'x';
	}
	else if (player1 % 2 == 1)
	{
		field[4] = 'x';
	}
	else if (player1 == 4)
	{
		field[7] = 'x';
	}
	else if (player1 == 6)
	{
		field[8] = 'x';
	}
	else field[6] = 'x';
}

int geto1Cell(char field[], int player)
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == 'o' and cell != player)
		{
			return cell;
		}
		else {}
	}
}

int getx1Cell(char field[], int comp)
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == 'x' and cell != comp)
		{
			return cell;
		}
		else {}
	}
}

void case2(char field[])
{
	int player = getoCell(field), comp = getxCell(field);
	
	if (player == 4)
	{
		case2Player4(field, comp);
	}
	else if (comp == 0)
	{
		case2Comp0(field, player);
	}
	else if (comp == 2)
	{
		case2Comp2(field, player);
	}
	else if (comp == 6)
	{
		case2Comp6(field, player);
	}
	else
	{
		case2Comp8(field, player);
	}
}

void case2Player4(char field[], int comp)
{
	if (comp == 2 or comp == 6)
	{
		field[8] = 'x';
	}
	else
	{
		field[2] = 'x';
	}
}

void case2Comp8(char field[], int player)
{
	if (player == 2 or player == 5)
	{
		field[6] = 'x';
	}
	else
	{
		field[2] = 'x';
	}
}

void case2Comp6(char field[], int player)
{
	if (player == 0 or player == 3)
	{
		field[8] = 'x';
	}
	else
	{
		field[0] = 'x';
	}
}

void case2Comp2(char field[], int player)
{
	if (player == 5 or player == 8)
	{
		field[0] = 'x';
	}
	else
	{
		field[8] = 'x';
	}
}

void case2Comp0(char field[], int player)
{
	if (player == 3 or player == 6)
	{
		field[2] = 'x';
	}
	else
	{
		field[6] = 'x';
	}
}

int getxCell(char field[])
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == 'x')
		{
			return cell;
		}
		else {}
	}
}

int getoCell(char field[])
{
	for (int cell = 0; cell < CELLS; cell++)
	{
		if (field[cell] == 'o')
		{
			return cell;
		}
		else {}
	}
}

void case0(char field[], char computer)
{
	int number = rand() % 4;

	if (number == 0)
	{
		field[0] = computer;
	}
	else if (number == 1)
	{
		field[2] = computer;
	}
	else if (number == 2)
	{
		field[6] = computer;
	}
	else
	{
		field[8] = computer;
	}
}

void input(char field[], char computer)
{
	while (true)
	{
		int number = rand() % 9;

		if (field[number] == ' ')
		{
			field[number] = computer;
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