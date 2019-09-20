/////////////////////////////////////////
// 알고리즘 분류 : Dynamic Programming //
/////////////////////////////////////////
#include<iostream>
using namespace std;
long long fac[1001] = { 0, };

int main()
{
	long long n = 0;
	cin >> n; //크기 n
	fac[1] = 1;
	fac[2] = 2;

	for (int i = 3; i < 1001; i++)
	{
		fac[i] = (fac[i - 1] + fac[i - 2]) % 10007;
	}

	cout << fac[n];

}