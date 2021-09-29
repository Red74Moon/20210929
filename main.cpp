#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//�迭 ����
	int Bingo[9];
	//�迭 �ʱ�ȭ
	for (int i = 0; i < 9; ++i)
	{
		Bingo[i] = i + 1;
	}
	//���� �߻�
	srand(static_cast<unsigned int>(time(nullptr)));
	//�迭 �ڸ��ٲ�
	for (int i = 0; i < 100; ++i)
	{
		//9�� �ڸ����� ������ ��ġ 2�� ����
		int index1 = rand() % 9;
		int index2 = rand() % 9;
		//������ ����� 2���� �� �ٲ�
		int Temp	  = Bingo[index1];
		Bingo[index1] = Bingo[index2];
		Bingo[index2] = Temp;
	}
	//�迭 ��� 3*3
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