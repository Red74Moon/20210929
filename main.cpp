#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int Bingo[9];

	for (int i = 0; i < 9; ++i)
	{
		Bingo[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < 100; ++i)
	{
		int index1 = rand() % 9;
		int index2 = rand() % 9;

		int Temp = Bingo[index1];
		Bingo[index1] = Bingo[index2];
		Bingo[index2] = Temp;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Bingo[i * 3 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << Bingo[i * 3 + j] << "\t";
		}
		cout << endl;
	}
	return 0;
}