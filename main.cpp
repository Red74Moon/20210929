#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//배열 선언
	int Bingo[9];
	//배열 초기화
	for (int i = 0; i < 9; ++i)
	{
		Bingo[i] = i + 1;
	}
	//난수 발생
	srand(static_cast<unsigned int>(time(nullptr)));
	//배열 자리바꿈
	for (int i = 0; i < 100; ++i)
	{
		//9개 자리수중 무작위 위치 2개 추출
		int index1 = rand() % 9;
		int index2 = rand() % 9;
		//무작위 추출된 2개의 값 바꿈
		int Temp	  = Bingo[index1];
		Bingo[index1] = Bingo[index2];
		Bingo[index2] = Temp;
	}
	//배열 출력 3*3
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