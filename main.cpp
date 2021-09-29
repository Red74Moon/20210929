
#include <iostream>
#include <conio.h>

using namespace std;

void Input();
void MapDraw();
void Precess();

//1.지도를 초기화한다.
int Map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int PlayerX = 3;
int PlayerY = 3;

char Key;

bool GameStauts = true;

int main()
{	
	MapDraw();

	while (GameStauts)
	{
		//2.입력을 받는다.
		Input();

		//3.처리한다. 
		//  플레이어를 움직인다.
		Precess();

		//4.지도를 그린다.
		MapDraw();
	}
	return 0;
}

void Input()
{
	cout << "W, A, S, D, Q(end) " << endl;
	Key = _getch();
}

void MapDraw()
{
	system("cls");
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << "P" << " ";
			}
			else if (Map[X][Y] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[X][Y] == 1)
			{
				cout << "X" << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Precess()
{
	switch (Key)
	{
		//UP
		case 'W':
		case 'w':
		{
			if (PlayerY == 1)
			{
				cout << "break" << endl;
			}
			else
			{
				PlayerY--;
			}
			break;
		}
		//Left
		case 'A':
		case 'a':
		{
			if (PlayerX == 1)
			{
				cout << "break" << endl;
			}
			else
			{
				PlayerX--;
			}
			break;
		}
		//Right
		case 'D':
		case 'd':
		{
			if (PlayerX == 8)
			{
				cout << "break" << endl;
			}
			else
			{
				PlayerX++;
			}
			break;
		}
		//Down
		case 'S':
		case 's':
		{
			if (PlayerY == 8)
			{
				cout << "break" << endl;
			}
			else
			{
				PlayerY++;
			}
			break;
		}
		case 'Q':
		case 'q':
		{
			GameStauts = false;
			break;
		}
		break;
	}

}
