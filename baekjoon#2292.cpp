#include <iostream>
using namespace std;
/////////////////////////////
// baekjoon algorithm 2292 //
//	사용언어 : c++		   //
/////////////////////////////

int main()
{
	int N = 0;
	int b = 0;
	int count = 1;
	int compare = 0;
	cin >> N;

	while (1)
	{
		compare = b * 6 + 1; //비교해주는 숫자
		if (N <= compare)
		{
			break;
		}
		b += count;
		count++;
	}

	cout << count;
}