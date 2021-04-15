#include <iostream>
#define N 3 // n - кол-во кубиков в линию. Изменить перед запуском

using namespace std;

/*1. ПРОСВЕТ. Куб состоит из n3(n в кубе) прозрачных и непрозрачных кубиков. Имеется ли хотя бы один просвет?*/
void explanation();

void cubesInACub(char cube[]);

void clearance(char cube[]);

char getСlearance(char cube[], char clearance, int n, int view);
int getViev(int i, int view);

bool isClearance(int i, char cube[], int view);
int getViewCub(int view);
char getCoutClearance(bool isClearance, int i, int view);
void coutClearanceView(int view);

void viewCub(char cube[]);
int getViewSection(char cube[], int cub);
void splittingLines(int number);
int getCubeWidth();

int main()
{
	char cube[N * N * N] = { 0 };

	explanation();

	cubesInACub(cube);

	viewCub(cube);

	clearance(cube);

	return 0;
}

void explanation()
{
	char sample = 0;

	sample = 1;
	cout << sample << " - the cube is transparent." << endl;

	sample = 2;
	cout << sample << " - the cube is not transparent." << endl << endl;
}

void cubesInACub(char cube[]) // Заполнение куба
{
	for (int i = 0; i < pow(N, 3); i++)
	{
		cube[i] = 1 + rand() % 2;
	}
}

void clearance(char cube[]) // Просвет
{
	char clearance = 0;
	clearance =	getСlearance(cube, clearance, 1, 1) + getСlearance(cube, clearance, N, 2) + getСlearance(cube, clearance, N, 3); 
	// Вид спереди + вид слева + вид сверху

	if (clearance == 0)
	{
		cout << "No clearance." << endl;
	}
	else {}
}

char getСlearance(char cube[], char clearance, int n, int view) // Вид
{	
	for (int i = 0; i < N * N * n; i++)
	{
		clearance += getCoutClearance(isClearance(i, cube, view), i, view);

		i += getViev(i, view);
	}

	return clearance;
}

int getViev(int i, int view)
{
	if (view == 2) // сбоку
	{
		return N - 1;
	}
	else if (view == 3) // слева
	{
		if ((i + 1) % N == 0)
		{
			return pow(N, 2) - N;
		}
		else return 0;
	}
	else return 0; // спереди
}

bool isClearance(int i, char cube[], int view)
{
	int numberCube = 0, cubeRow = i;
	
	while (numberCube < N)
	{
		if (cube[cubeRow] == 2)
		{
			return false;
		}

		cubeRow += getViewCub(view);

		numberCube++;
	}

	return true;
}

int getViewCub(int view)
{
	if (view == 1) // спереди
	{
		return N * N;
	}
	else if (view == 2) // сбоку
	{
		return 1;
	}
	else return N; // сверху
}

char getCoutClearance(bool isClearance, int i, int view)
{
	if (isClearance)
	{
		cout << "The cube is clearance through the " << i + 1 << " cube ";
		coutClearanceView(view);

		return 1;
	}
	else return 0;
}

void coutClearanceView(int view)
{
	if (view == 1) // спереди
	{
		cout << "at the front." << endl;
	}
	else if (view == 2) // сбоку
	{
		cout << "on the leftward." << endl;
	}
	else cout << "at the above." << endl; // сверху
}

void viewCub(char cube[])
{
	cout << "Front view of the cube in sections: " << endl << endl;
	int cub = 0;

	for (int section = 0; section < N; section++)
	{
		cout << section + 1 << " section:" << endl;

		cub = getViewSection(cube, cub);
	}
}

int getViewSection(char cube[], int cub)
{
	int number = 0;

	while (number < pow(N, 2))
	{
		cout.width(getCubeWidth());
		cout << cub + 1 << ") " << cube[cub];

		if ((cub + 1) % N == 0)
		{
			cout << endl;

			splittingLines(number);
		}
		else
		{
			cout << "|";
		}
		number++;
		cub++;
	}

	return cub;
}

void splittingLines(int number)
{
	if (number < pow(N, 2) - 1)
	{
		for (int a = 1; a < (getCubeWidth() + 4) * N; a++)
		{
			if (a % (getCubeWidth() + 4) == 0)
			{
				cout << "+";
			}
			else
			{
				cout << "-";
			}
		}
	}
	cout << endl;
}

int getCubeWidth()
{
	int width = 0, maxCub = pow(N, 3);

	while (maxCub > 0)
	{
		maxCub /= 10;
		width++;
	}

	return width;
}