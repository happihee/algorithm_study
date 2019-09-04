#include <iostream>
using namespace std;
//////////////////////////////
// baekjoon algorithm 1193  //
// 사용언어 : c++			//
//////////////////////////////
int main()
{
	int N = 0;
	int df = 0;
	int b = 1;
	int compare = 1;
	int denor = 0; //분모
	int numer = 0; //분자
	cin >> N;

	while (1)
	{
		if (N <= compare)
		{
			if (b % 2 == 0) //짝수번째 일 때
			{
				denor = b;
				numer = 1;
				for (int i = 1; i < N - df; i++)
				{
					denor--;
					numer++;
				}
			}
			else
			{
				denor = 1;
				numer = b;
				for (int i = 1; i < N - df; i++)
				{
					denor++;
					numer--;
				}
			}
			break;
		}
		df = compare;
		b++;
		compare += b;	
	}
	cout << numer << "/" << denor<< endl;
	return 0;
}
