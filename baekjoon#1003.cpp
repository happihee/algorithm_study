#include<iostream>
using namespace std;
int CountOne[41] = { 0, };
int CountZero[41] = { 0, };

int main()
{
	//////���� ��/////
	CountOne[0] = 0;
	CountZero[0] = 1;
	CountOne[1] = 1;
	CountZero[1] = 0;
	//////////////////
	//40������ fibonacci�� ������ ���� �迭//
	for (int i = 2; i < 42;i++)
	{
		CountOne[i] = CountOne[i - 2] + CountOne[i - 1];
		CountZero[i] = CountZero[i - 2] + CountZero[i - 1];
	}
	int testcase = 0;
	int N[5005] = { 0, };
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> N[i];
	}
	for (int i = 0; i < testcase; i++)
	{
		cout << CountZero[N[i]] << " " << CountOne[N[i]] << endl;
	}
}