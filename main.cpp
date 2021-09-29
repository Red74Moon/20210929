
#include <iostream>
#include <conio.h>

using namespace std;

void Input();
void MapDraw();
void Precess();
void MovePlayer(int XDirection, int YDirection);
bool IsGoal();

//1.������ �ʱ�ȭ�Ѵ�.
int Map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,0,0,1,0,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,9,1}
};
int PlayerX = 4;
int PlayerY = 4;

int Key;

bool GameStauts = true;

int main()
{	
	while (GameStauts)
	{
		MapDraw();

		//2.�Է��� �޴´�.
		Input();

		//3.ó���Ѵ�. 
		//  �÷��̾ �����δ�.
		Precess();

		//4.������ �׸���.
		MapDraw();
	}
	return 0;
}

void Input()
{
	cout << "W(U), A(L), S(D), D(R), G(END)" << endl;
	Key = _getch();
	if (Key == 0x00 || Key == 0xE0) 
	{
		Key = _getch();
	}
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
			else if (Map[Y][X] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[Y][X] == 1)
			{
				cout << "X" << " ";
			}
			else if (Map[Y][X] == 9)
			{
				cout << "G" << " ";
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
			MovePlayer(0, -1);
			break;
		}
		//Left
		case 'A':
		case 'a':
		{
			MovePlayer(-1, 0);
			break;
		}
		//Right
		case 'D':
		case 'd':
		{
			MovePlayer(1, 0);
			break;
		}
		//Down
		case 'S':
		case 's':
		{
			MovePlayer(0, 1);
			break;
		}
		break;
	}
	if (IsGoal())
	{
		GameStauts = false;
	}
}

void MovePlayer(int XDirection, int YDirection)
{
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	//�̸�����
	if (Map[NewPlayerY][NewPlayerX] == 0 || 
		Map[NewPlayerY][NewPlayerX] == 9)
	{
		//�̵�
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	} 
}

bool IsGoal()
{
	return Map[PlayerY][PlayerX] == 9 ? true : false;
}
